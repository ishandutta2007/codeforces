#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll p[29],n,m;
ll fr[29];
ll go(vector<int>v)
{
    for(int i=0;i<=n;i++)fr[i]=0;
    for(int i=0;i<n;i++)
        fr[n+1-v[i]]++;
    for(int i=1;i<n;i++)fr[i]+=fr[i-1];
    ll res=1;
    for(int i=1;i<=n;i++)
        res=(res*(fr[i-1]-i+1))%mod;
    res=(p[n]-res+mod)%mod;
    return res;
}
vector<int>v[50009];
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2)return (x*pw(x,y-1))%mod;
    ll w=pw(x,y/2);
    return (w*w)%mod;
}
ll inv(ll x)
{
    return pw(x,mod-2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
p[0]=1;
for(int i=1;i<=20;i++)p[i]=(i*p[i-1])%mod;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++){
    int x;
    cin>>x;
    v[j].push_back(x);
    }
}
ll ans=0;
for(int i=0;i<m;i++)ans=(ans+go(v[i]))%mod;
ans=(ans*inv(p[n]))%mod;
cout<<ans;

    return 0;
}