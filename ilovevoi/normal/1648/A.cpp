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

const ll maxn=2e5+30;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7


vector<ll> adj[2][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("t.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll n, m;
    cin>> n>> m;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            ll x;
            cin>> x;
            adj[0][x].pb(i);
            adj[1][x].pb(j);
        }
    }
    ll ans=0;
    for (int h=0;h<=1;h++)
    {
        for (int t=0;t<maxn;t++)
        {
            if (!adj[h][t].size()) continue;
            vector<ll> vt=adj[h][t];
            sort(vt.begin(),vt.end());

            ll len=vt.size();
            for (ll i=0;i<vt.size();i++)
            {
                ans=(ans+(i-(len-i-1))*vt[i]);
            }
          //  cout <<ans<<" "<<t<<" "<<h<<" chk1"<<endl;
        }
    }
    cout <<ans<<endl;
}