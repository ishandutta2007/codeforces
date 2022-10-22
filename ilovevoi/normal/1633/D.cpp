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

const ll maxn=1e3+100;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7

ll a[maxn];
ll c[maxn];

ll dp[maxn];
ll dp1[2][maxn*12];

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
    for (int i=1;i<maxn;i++)
    {
        dp[i]=base;
    }
    dp[1]=0;
    ll mx=0;
    for (int i=1;i<maxn;i++)
    {
        for (int j=1;j<=i;j++)
        {
            ll p=i+(i/j);
           if (p<maxn) dp[p]=min(dp[i]+1,dp[p]);
        }
        mx=max(mx,dp[i]);
    }
    //cout <<mx<<endl;
    ll t;
    cin>> t;
    while (t--)
    {
        ll n, k;
        cin>> n>> k;
        k=min(k,n*12);
        for (int j=0;j<=k;j++) dp1[0][j]=-base,dp1[1][j]=-base;
         dp1[0][0]=0;
        for (int i=1;i<=n;i++) cin>> a[i];
        F(i,1,n) cin>> c[i];
        ll ans=0;
        F(i,1,n)
        {
            ll nw=i%2;
            ll pre=1-nw;
            for (int j=0;j<=k;j++)
            {
                if (j+dp[a[i]]<=k)
                {
                    dp1[nw][j+dp[a[i]]]=max(dp1[nw][j+dp[a[i]]],dp1[pre][j]+c[i]);
                    ans=max(ans,dp1[nw][j+dp[a[i]]]);
                }
                dp1[nw][j]=max(dp1[nw][j],dp1[pre][j]);
                ans=max(ans,dp1[nw][j]);
                dp1[pre][j]=-base;
            }
        }
        cout <<ans<<endl;
    }
}