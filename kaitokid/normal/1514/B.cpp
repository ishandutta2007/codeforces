#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   while(t--)
   {
       ll n,k;
       cin>>n>>k;
       ll ans=1;
       for(int i=0;i<k;i++)
       {
           ans=(ans*n)%mod;
       }
      cout<<ans<<endl;
   }
    return 0;
}