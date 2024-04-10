#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll a[200009],b[200009],n,ans;
int main()
{
ios::sync_with_stdio(0);
cin>>n;
for(ll i=0;i<n;i++)
{
cin>>a[i];
a[i]*=(i+1)*(n-i);
}
for(ll i=0;i<n;i++)
cin>>b[i];
sort(a,a+n);
sort(b,b+n);
for(ll i=0;i<n;i++)
{
a[i]%=mod;
ans+=(a[i]*b[n-i-1])%mod;
ans%=mod;


}
cout<<ans;
return 0;}