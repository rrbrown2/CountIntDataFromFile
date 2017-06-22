/*
 Reads 100 integers, and computes the sum of those integers (excluding negative numbers), mean, median,
 largest positive integer, smallest positive integer, range, standard deviation, number of negative integers
 and their sum, and number of positive integers and their sum
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#define SIZE 100
using namespace std;

 // Declare variables
int numbers[SIZE];
int totalElements;

//function prototypes
double mean();
double median();
int largest_positive_integer();
int smallest_positive_integer();
int range();
double standard_deviation();
int number_of_negative_int_onfile();
int number_of_positive_int_onfile();
int negative_Sum();
int positive_Sum();
void output();
void selectionSort(int arr[], int num);
int smallest_number();

ifstream infile;
ofstream outputfile;

int main()
{
    // open files
    infile.open("read.txt");
    outputfile.open("write.txt");
    totalElements = 0;

    // if there is no data on file return message and exit program
    if ( infile.peek() == std::ifstream::traits_type::eof() )
    {
        outputfile << "There is no data on file";
        exit(0);
    }

    // loops through to end of file if there is data
    while(!infile.eof())
    {
        infile >> numbers[totalElements];
        totalElements++;
        if (infile.fail()) // used to validate data in the file
        {
            infile.clear(); // used to avoid reading the same line over and over again
            continue; // then go to the next line
        }

        if (totalElements >= 100)
        {
            outputfile << "not all data read in, file exceeds array capacity of 100" << endl;
            break;
        }

    }
    selectionSort(numbers, totalElements); // sort the numbers
    output();
    // close files
    infile.close();
    outputfile.close();
    return 0;
}

// data output to screen
void output()
{
   outputfile << "The mean is " << setprecision(2) << fixed <<  mean() << endl;
   outputfile << "The median is " << setprecision(2) << fixed << median() << endl;
   outputfile << "The largest positive integer is " << largest_positive_integer() << endl;
   outputfile << "The smallest positive integer is " << smallest_positive_integer() << endl;
   outputfile << "The range is " << range() <<  endl;
   outputfile << "The standard deviation is " << standard_deviation() << endl;
   outputfile << "There were " << number_of_negative_int_onfile() << " negative integers on the file with a sum of " << negative_Sum() << endl;
   outputfile << "There were " << number_of_positive_int_onfile() << " positive integers on the file with a sum of " << positive_Sum() << endl;

}

// find the average
double mean()
{
    int sum=0;
    for (int i=0; i<totalElements; i++ )
        sum += numbers[i];
    double average = (double)sum / (double)totalElements;
    return average;
}

double median()
{
    double median;
    int topIndex = totalElements - 1;
    if (topIndex % 2 != 0){
        median = ( numbers[topIndex/2] + numbers[ (topIndex/2) +1]) / 2.0;
    }
    else{
        median = numbers[topIndex/2];
    }
    return median;
}

int largest_positive_integer()
{
    int n = 0;
    if (numbers[totalElements-1] > 0)
        n = numbers[totalElements-1];
    return n;
}

// finds the smallest number in the array
int smallest_positive_integer()
{
    int n = 0;
    for (int i=0; i < totalElements; i++){
        if (numbers[i] >= 0){
            n = numbers[i];
            break;
        }
    }
    return n;
}

// returns the largest - smallest numbers in the array
int range()
{
    // Initialising smallest and largest numbers to first number in array
    int smallest = numbers[0];
    int largest = numbers[0];

    // Looping on each element of array starting from index 1 till the end
    for(int i = 1; i < totalElements; i++) {

      // If the current number we have is smaller than 'smallest' then it is smallest
      // number so far
      if (numbers[i] < smallest) {
        smallest = numbers[i];
      }

      // If the current number we have is bigger than 'largest' then it is biggest
      // number so far
      if (numbers[i] > largest) {
        largest = numbers[i];
      }
    }

    // Range value = largest - smallest
    int range = largest - smallest;
    return range;
}

// returns the standard deviation of the array.
double standard_deviation()
{
    double average = mean();
    double sum=0;
    for (int i = 0; i < totalElements; i++)
    {
        sum += pow(numbers[i] - average,2);
    }
    double answer = sqrt(sum / (double)totalElements); // cast total elements to a double
    return answer;
}

// sorts the array from smallest to largest
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, tmp;
    for(i =0; i < n - 1; i++)
    {
        minIndex = i;
        for(j = i +1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
            if(minIndex != i)
            {
                tmp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = tmp;
            }
    }
}
// smallest number in the array
int smallest_number()
{
    int smallest = numbers[0];
    for (int i=0; i < totalElements; i++){
        if (numbers[i] < smallest)
                smallest = numbers[i];
    }
    return smallest;
}

int number_of_negative_int_onfile(){
    int n=0;
    for (int i=0; i<totalElements; i++ )
        if (numbers[i] < 0){
            n++;
        }
    return n;
}

int number_of_positive_int_onfile(){
    int n=0;
    for (int i=0; i<totalElements; i++ )
        if (numbers[i] >= 0){
            n++;
        }
    return n;
}

int negative_Sum()
{
    int n=0;
    for (int i=0; i<totalElements; i++ )
        if (numbers[i] < 0){
            n+=numbers[i];
        }
    return n;
}

int positive_Sum()
{
    int n=0;
    for (int i=0; i<totalElements; i++ )
        if (numbers[i] > 0){
            n+=numbers[i];
        }
    return n;
}
