#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==1)return (a*pw(a,b-1))%mod;
    ll q=pw(a,b/2);
    return (q*q)%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    ll ans=pw(2,m)-1;
    ans= pw(ans,n);
    cout<<ans;
    return 0;
}