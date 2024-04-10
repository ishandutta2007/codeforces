#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
   ll n;
   cin>>n;
   cin>>a[0];
   int u=a[0];
   for(int i=1;i<n;i++){cin>>a[i];u&=a[i];}
   ll z=0;
   for(int i=0;i<n;i++)if(a[i]==u)z++;
   ll ans=z*(z-1);
   ans%=mod;
   for(int i=1;i<=n-2;i++)ans=(ans*i)%mod;
   cout<<ans<<endl;
    }
    return 0;
}