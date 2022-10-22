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

const ll maxn=1e6+100;
const ll mod=1000003 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7
ll dp[maxn][2];

ll cst[2];
ll a[maxn];

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
        ll n, m;
        cin>> n>> m;
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        ll len=0;
        for (int i=1;i<=m;i++)
        {
            ll x;
            cin>> x;
            len=__gcd(len,x);
        }
        cst[0]=0;
        cst[1]=0;
        for (int i=1;i<=len;i++)
        {
            vector<ll> vt;
            for (int j=i;j<=n;j+=len)
            {
                vt.pb(a[j]);
            }
            for (int i=0;i<=vt.size();i++)
            {
                for (int t=0;t<=1;t++) dp[i][t]=-base;
            }
            dp[0][0]=0;
            for (int i=1;i<=vt.size();i++)
            {
                for (int t=0;t<=1;t++)
                {
                    for (int h=0;h<=1;h++)
                    {
                        dp[i][t^h]=max(dp[i][t^h],dp[i-1][t]+(h==0?1:-1)*vt[i-1]);
                    }
                }
            }
            cst[0]+=dp[vt.size()][0];
            cst[1]+=dp[vt.size()][1];
        }
        cout <<max(cst[0],cst[1])<<endl;
    }

}