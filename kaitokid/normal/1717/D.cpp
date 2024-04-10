#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    ll r=pw(x,y/2);
    r=(r*r)%mod;
    if(y%2)r=(r*x)%mod;
    return r;
}
ll p[100009],inv[100009];
ll c(ll x,ll y)
{
    return (((p[x]*inv[y])%mod)*inv[x-y])%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<=100001;i++)p[i]=(p[i-1]*i)%mod;
    inv[100001]=pw(p[100001],mod-2);
    for(int i=100000;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;

    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<=min(k,n);i++)
    {
        ans+=c(n,i);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}