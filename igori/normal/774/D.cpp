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
     int n;
     int l;
     int r;
     cin>>n>>l>>r;
     l--;
     r--;
     int t=1;
     int a[100000];
     int b[100000];
     for(int i=0; i<n; i++)
       cin>>a[i];
     for(int i=0; i<n; i++)
       cin>>b[i];
     for(int i=0; i<l; i++)
     {
          if(a[i]!=b[i])
             t=0;
     }
     for(int i=r+1; i<n; i++)
     {
          if(a[i]!=b[i])
             t=0;
     }
     if(t==1)
       cout<<"TRUTH";
       else
       cout<<"LIE";
}