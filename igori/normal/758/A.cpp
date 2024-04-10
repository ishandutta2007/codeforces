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
//Problem 758A


int main()
{
      int n;
      cin>>n;
      int a[10000]={0};
      int max=0;
      for(int i=0; i<n; i++)
      {
           cin>>a[i];
           if(a[i]>max)
              max=a[i];
      }
      int ans=0;
      for(int i=0; i<n; i++)
      {
           ans+=max-a[i];
      }
      cout<<ans;
    
    
    
    
    
    
    
        
    
    
}