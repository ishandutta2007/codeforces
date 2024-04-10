#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2)return (a*pw(a,b-1))%mod;
    ll p=pw(a,b/2);
    return (p*p)%mod;
}
ll dp[204009][3];
ll go(ll x,ll u)
{
    //cout<<x<<" "<<u<<endl;
    if(x==0)
    {
        if(u==0)return 1;else return 0;
    }
    if(dp[x][u]!=-1)return dp[x][u];
  ll ans=go(x-1,1-u);
  if(u==1)ans+=go(x-1,1);
  ans%=mod;
  return dp[x][u]=ans;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll p=go(n,1);

   ll s=pw(2,n);
   ll d=p*pw(s,mod-2);
   d%=mod;
   cout<<d;
return 0;
}