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
const ll mod=998244353 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7


ll dp[22][2];
ll a, b;
ll nw;

ll f(ll id,ll e)
{
    if (id==-1) return 0;
    if (dp[id][e]!=-1) return dp[id][e];
    ll ans=base;
    for (ll t=0;t<=1;t++)
    {
        ll k=0;
        if (a&(1ll<<id)) k=1;
        ll p=0;
        if (nw&(1ll<<id)) p=1;
     //   cout <<nw<<" wtf"<<endl;
        if (e||(k<=t))
        {
            ans=min(ans,f(id-1,(e|(k<t)))+(t|p)*(1ll<<id)+t*(1ll<<id));
        }
    }
    return dp[id][e]=ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll t;
    cin>> t;
    while (t--)
    {

        cin>> a>> b;
        ll ans=(b-a);
        for (int j=b;j<=b+(b-a);j++)
        {
            nw=j;
            memset(dp,-1,sizeof(dp));
            /*if (j==b+1)
            {
                cout <<f(21,0)<<" chk"<<endl;
            }*/
            ans=min(ans,(j-b)+1+f(21,0)-a-j);
        }
        cout <<ans<<endl;
    }
}