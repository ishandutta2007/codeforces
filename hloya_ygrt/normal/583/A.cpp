#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
   int n,a[10000],a1[10000];
   int o[10000];
   for (int i=0;i<n*n;i++){
    a[i]=0;
    a1[i]=0;}

   cin>>n;
   int l=0;
   for (int i=0;i<n*n;i++)
   {
       int h,v;
       cin>>h>>v;
       if (a[h-1]==0&&a1[v-1]==0)
       {
           o[l]=i+1;
           l++;
           a[h-1]=1;
           a1[v-1]=1;
       }

   }
   for(int i=0;i<l;i++){
    cout<<o[i]<<endl;
   }
    return 0;
}