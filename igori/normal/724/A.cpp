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
//Problem 724A


int main()
{
      string s1;
      string s2;
      cin>>s1>>s2;
      int a=1;
      int b=1;
      if(s1=="monday")
         a=0;
      if(s1=="tuesday")
         a=1;
      if(s1=="wednesday")
      a=2;
      if(s1=="thursday")
      a=3;
      if(s1=="friday")
      a=4;
      if(s1=="saturday")
      a=5;
      if(s1=="sunday")
      a=6;
      if(s2=="monday")
         b=0;
      if(s2=="tuesday")
         b=1;
      if(s2=="wednesday")
      b=2;
      if(s2=="thursday")
      b=3;
      if(s2=="friday")
      b=4;
      if(s2=="saturday")
      b=5;
      if(s2=="sunday")
      b=6;
      if((a+28)%7==b)
      {
           cout<<"YES";
           return 0;
      }
      if((a+30)%7==b)
      {
           cout<<"YES";
           return 0;
      }
      if((a+31)%7==b)
      {
           cout<<"YES";
           return 0;
      }
      cout<<"NO";
    
    
    
    
    
    
    
        
    
    
}