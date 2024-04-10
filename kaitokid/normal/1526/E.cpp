#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll a[200009],id[200009];
ll z[500009];
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2)return (x*pw(x,y-1))%mod;
ll rs=pw(x,y/2);
return (rs*rs)%mod;
}
ll inv(ll x)
{
    return pw(x,mod-2);
}
ll c(ll x,ll y)
{
    ll res= (z[x]*inv(z[y]))%mod;
    res=(res*inv(z[x-y]))%mod;
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   z[0]=1;
   for(ll i=1;i<=500000;i++)z[i]=(z[i-1]*i)%mod;
   ll n,k;
   cin>>n>>k;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       id[a[i]]=i;
   }
   id[n]=-1;
   ll p=0;
   for(int i=0;i<n-1;i++)
    if(id[a[i]+1]>id[a[i+1]+1])p++;
  ll r=k-1-p;
  if(r<0){cout<<0;return 0;}

    cout<<c(n+r,r);
}