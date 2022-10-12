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
   int k;
   int n;
   long long ans=0;
   int m[1000000]={0};
   cin>>n;
   cin>>k;
   for(int i=0; i<n; i++)
      cin>>m[i];
      for(int i=0; i<n; i++)
      {
           if(m[i]%k==0)
              ans+=m[i]/k;
           else
              ans+=m[i]/k+1;
      }
    if(ans%2==0)
    cout<<ans/2;
    else
    cout<<ans/2+1;
}