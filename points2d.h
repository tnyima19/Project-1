/*
Tenzing Nyima
Date: Sept 16 2021
CSCI 335
Submitted to Professor Ionnis Stamos
This is an assignement where we make the "Big Five"

Take input of points multiple points (x,y) and store them in an array creating double array.


*/
#ifndef CSCI335_HOMEWORK1_POINTS2D_H_g
#define CSCI335_HOMEWORK1_POINTS2D_H_g

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Points2d stores is an 2d array of points. 
//each array contains two arrays which store x and y coordinates of a point
// {{1,2} 
//{2,3}
//{4,5}}
// Points2D of size 3 
// and one point is sequence_, which consists two arrays hence its type<Object,2>
// object is tempalte, 2 is the size of the specifiect array.
template<typename Object>
class Points2D {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2D(){sequence_ =nullptr; size_ =0;}

  // Copy-constructor.
  Points2D(const Points2D &rhs) {
    size_= rhs.size_;
    sequence_= new std::array<Object,2>[size_];
    for(size_t i=0;i<rhs.size_;i++)
    {
      sequence_[i]= rhs.sequence_[i];
    }

 
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2D copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2D& operator=(const Points2D &rhs){
      Points2D copy = rhs;
      std::swap(*this,copy);
      return *this;
  }

  // Move-constructor. 
  Points2D(Points2D &&rhs) : sequence_{rhs.sequence_},size_{rhs.size_}{rhs.sequence_ = nullptr;rhs.size_=0;}

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2D& operator=(Points2D &&rhs){
        std::swap(sequence_,rhs.sequence_);
        std::swap(size_, rhs.size_);
        return *this;
    }

  ~Points2D(){delete sequence_; sequence_ = nullptr;}

  // End of big-five.

  // One parameter constructor.
  // creates a new array and puts the respective data into place from array item.
  Points2D(const std::array<Object, 2>& item) {
    // Provide code.
    size_=1;
    sequence_ = new std::array<Object,2>[size_];//dymically creating array
    sequence_[0][0] = item[0];
    sequence_[0][1] = item[1];
    
  }


  // Read a chain from standard input.
  void ReadPoints2D() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    // Allocate space for sequence.
    // Add code here. 
    size_ = size_of_sequence;
    delete[]sequence_;// delete the old value of  sequence_ just incase
    sequence_=new std::array<Object,2>[size_]; // dynamically create a new sequence of the size from above

    // I THINK I NEED TO CALL CONSTRUCTOR
    //Points2D one;
    
    Object token;// where input will be stored and given to the sequence_ array.
    
     for (int i= 0; input_stream>>token; ++i) {
       // Read coordinates.
       sequence_[i][0]=token;// sequence_[i][0] is equal to the first input
       input_stream>>token;
       sequence_[i][1]=token; // sequence_[i][0] is equal to second input
       // goes on until all inputs are stored in sequence_ and its particular size.
       
     }
     std::cout<<std::endl;
      //cout << std::endl;
      
  }
    
  
  // returns the number of 2d points.
  size_t size() const {
    // Code missing.
    return size_;// the number of 2d points.
    
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const { 
    // Code missing.
    if(location<=size_)
      return sequence_[location];// returns the locaiton of the points if locaiton is less than the size

    
    else
      abort();

}
    

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
   // Code missing.
   //std::cout<<"error here"<<std::endl;
   Points2D new_point;
   if(c1.size_>=c2.size_)
      new_point.size_=c1.size_;// size of hte new point equals the larger size from c1.size or c2.size
    else if(c2.size_>c1.size_)
      new_point.size_=c2.size_;// same as above
    

    new_point.sequence_ = new std::array<Object,2>[new_point.size_];
    for(size_t i=0;i<new_point.size_;i++){
      if(i>=c2.size_){// if new point's size is greate than c2.size appendation takes place
        new_point.sequence_[i][0] = c1.sequence_[i][0] + 0;// appending rest of the c1. to new point
        new_point.sequence_[i][1] = c1.sequence_[i][1] + 0;// same here
      }
      else if(i>=c1.size_){ // if new point's size if greater than c1.size, here appendation takes place
        new_point.sequence_[i][0] = c2.sequence_[i][0] + 0; // appending rest of c2 to new_point
        new_point.sequence_[i][1] = c2.sequence_[i][1] + 0;
      }
      else{// when c1, c2 have same size and new_point also has same size.
        new_point.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];// will simply add the numbers who are in the same order
        new_point.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];// same here

      }
      
    }
    //out<<std::endl;
    return new_point;// return new created point.
      
  
 }

 // Overloading the << operator.
 //outputs the array of 2d points, in clear way (2,0) (5,0)...
 friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2) {
     //out<<"{";
      //for(int i=0;i<some_points2.size_;i++)
     for(size_t y=0;y<some_points2.size_;y++)
     {
      out<<"("<<some_points2.sequence_[y][0]<<", "<<some_points2.sequence_[y][1]<<") ";
     }
     if(some_points2.sequence_ == nullptr)// when the sequence_ is empty 
      out<<"()";// if empty return empty bracket
     out<<std::endl;
     
     return out;


 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2D_H_
