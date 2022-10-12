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
     int m;
     int k;

     cin>>n>>m>>k;
     m--;
     int a[1000];
     for(int i=0; i<n; i++)
       cin>>a[i];
     int ans1=99999,ans2=99999;
     for(int i=m+1; i<n; i++)
     {
          if((a[i]<=k)&&(a[i]>0))
          {
               ans1=(i-m)*10;
               break;
          }
     }
     for(int i=m-1; i>=0; i--)
     {
        if((a[i]<=k)&&(a[i]>0))
          {
               ans2=(m-i)*10;
               break;
          }
     }
     //cout<<ans1<<" "<<ans2<<" ";
     cout<<min(ans1,ans2);
     
     
}