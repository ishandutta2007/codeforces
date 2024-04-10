#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

#define then ;
#define cin(n); int n; cin>>n;
#define stop return 0;
//IgorI
//It is true or false
//Is it true or false?

int main()
{
     int a[100000];
     int was[100001]={0};
     cin(n);
     int need=n;
     for(int i=0; i<n; i++)
     {
          cin>>a[i];
          was[a[i]]=1;
          while(was[need]==1)
          {
               cout<<need<<" ";
               need--;
          }
          cout<<"\n";
     }
     
}