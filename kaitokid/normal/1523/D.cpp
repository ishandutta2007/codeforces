#include<bits/stdc++.h>
using namespace std;
#include<random>
#include <chrono>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll n,m,p;
ll a[200009];
ll dp[32777],rs,ans;
 vector<ll>u;
 ll bt[32777];
void ch(ll r,ll x)
{
if(bt[r]<=rs)return;
rs=bt[r];
ll tmp=0;
for(ll i=0;i<u.size();i++)
    if(r&(1LL<<i))tmp|=(1LL<<u[i]);
ans=tmp;

}
void go(ll x)
{
    u.clear();
    ll g=a[x];
    for(ll i=0;i<m;i++)
        if((1LL<<i)&g)u.push_back(i);
    for(ll i=0;i<(1<<p);i++)dp[i]=0;
    ll q=(1LL<<p)-1;
    for(ll i=0;i<n;i++)
    {   ll r=0;
        for(ll j=0;j<u.size();j++)
        if(a[i]&(1LL<<u[j]))r|=(1LL<<j);
        dp[(q^r)]++;
    }
  for(ll j=0;j<p;j++)
      for(ll i=0;i<(1<<p);i++)
      if(i&(1LL<<j))dp[i]+=dp[(i^(1LL<<j))];
      for(ll i=0;i<(1<<p);i++)
        if(dp[i]>=(n+1)/2)ch((q^i),x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<=(1<<15);i++)
        for(int j=0;j<15;j++)if(i&(1<<j))bt[i]++;
    cin>>n>>m>>p;
    rs=-1;
    for(int i=0;i<n;i++)
    {
        char c;
        for(int j=0;j<m;j++)
        {
            cin>>c;
            if(c=='1')a[i]|=(1LL<<j);
        }
    }
    for(int i=0;i<30;i++)
    {
        go(rng()%n);
    }
    for(ll i=0;i<m;i++)if(ans&(1LL<<i))cout<<1;
    else cout<<0;
    return 0;
}