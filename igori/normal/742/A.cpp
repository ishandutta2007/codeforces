#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
#define make(n) for(int i=0; i<n; i++)
//IgorI
//It is true or false
//Is it true or false?

//Codeforces 
//Problem 742A


int main()
{
      int n;
      cin>>n;
      if(n==0)
      {
           cout<<1;return 0;
      }
      if(n%4==1)
         cout<<8;
      if(n%4==2)
         cout<<4;
      if(n%4==3)
        cout<<2;
      if(n%4==0)
        cout<<6;
    
    
    
    
    
    
    
        
    
    
}