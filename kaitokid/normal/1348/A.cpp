#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       ll a=0,b=0;
       a=(1<<n);
       for(int i=1;i<n/2;i++)a+=(1<<i);
       for(int i=n/2;i<n;i++)b+=(1<<i);
       cout<<a-b<<endl;
   }
   return 0;
}