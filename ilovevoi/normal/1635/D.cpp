/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for (ll i=a;i<=b;i++)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+100;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 6/7


ll a[maxn];
ll n;

bool chk(ll x)
{
    ll l=1, h=n;
    while (l<=h)
    {
        ll mid=(l+h)/2;
        if (a[mid]>=x) h=mid-1;
        else l=mid+1;
    }
    if (a[l]==x) return true;
    else return false;
}
ll  p;
ll dp[maxn];
ll f[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("shortestpath.inp", "r"))
    {
        freopen("shortestpath.inp", "r", stdin);
        freopen("shortestpath.out", "w", stdout);
    }
     cin>> n>> p;
     F(i,1,n)
     {
         cin>> a[i];
     }
     dp[0]=1;
     f[0]=1;
     for (int i=1;i<maxn;i++)
     {
         dp[i]=(dp[i-1]+(i>=2?dp[i-2]:0))%mod;
         f[i]=(f[i-1]+dp[i])%mod;
     }
     sort(a+1,a+n+1);
     ll ans=0;
     for (int i=1;i<=n;i++)
     {
         ll nw=(a[i])/2;
         bool kt=true;
         bool chk1=true;
         ll pre=a[i]%2;
         ll len=(pre==0);
         ll sl=1;
         while (nw)
         {
             sl++;
             if (chk(nw))
             {

                 if (kt&&len%2==0)
                 {
                 //    cout <<i<<" "<<a[i]<<" "<<nw<<endl;
                     chk1=false;
                 }
             }
             ll t=pre;
             pre=nw%2;
             if (pre==0) len++;
             else
             {
                 if (len%2!=0) kt=false;
                 len=0;
             }
             nw/=2;
         }
         if (chk1)
         {
             //cout <<a[i]<<endl;
             if (p>=sl)
             {
                 ans=(ans+f[p-sl])%mod;
             }
         }
     }
     cout <<ans<<endl;
}