#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

 int main(){
     int n,a[1005],k=0,s=0;
     cin>>n;
     for (int i=0;i<n;i++)
        cin>>a[i];

     int r=n-a[0];
     for (int i=0;i<n;i++)
     {
         if (i%2==0)
         {
             a[i]+=r;
             if (a[i]>=n) a[i]-=n;
         } else
         {
             a[i]-=r;
             if (a[i]<0) a[i]+=n;
         }
     }
     for (int i=0;i<n;i++)
     {
            if (a[i]!=i)
            {
                cout<<"No";
                return 0;
            }
     }
     cout<<"Yes";

return 0;
 }