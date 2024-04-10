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


vector<ll> adj[maxn];
pll dp[maxn][2];

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
    ll t;
    cin>> t;
    while (t--)
    {
        ll n, m;
        cin>> n>> m;
        ll s, t;
        cin>> s>> t;
        F(i,1,m)
        {
            ll x, y;
            cin>>x>> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> q;
        for (int t=0; t<=n; t++)
        {
            for (int h=0; h<=1; h++)
            {
                dp[t][h].ff=base;
                dp[t][h].ss=0;
            }
        }
        dp[s][0].ff=0;
        dp[s][0].ss=1;
        q.push(make_pair(0,make_pair(s,0)));
        while (!q.empty())
        {
            auto p=q.top();
            q.pop();
            ll u=p.ss.ff;
            ll t=p.ss.ss;
            if (dp[u][t].ff!=p.ff)
                continue;

            for (auto to:adj[u])
            {
                for (int h=0; h<=1; h++)
                {
                    if (dp[to][h].ff>dp[u][t].ff+1)
                    {
                        dp[to][h].ff=(dp[u][t].ff+1);
                        dp[to][h].ss=(dp[u][t].ss);
                        q.push(make_pair(dp[to][h].ff,make_pair(to,h)));
                        break;
                    }
                    else if (dp[to][h].ff==dp[u][t].ff+1)
                    {
                        dp[to][h].ff=(dp[u][t].ff+1);
                        dp[to][h].ss=(dp[to][h].ss+dp[u][t].ss)%mod;
                        break;
                    }
                }
            }
        }
        if (dp[t][1].ff-1!=dp[t][0].ff)
            dp[t][1].ss=0;
        cout <<(dp[t][1].ss+dp[t][0].ss)%mod<<endl;
        for (int i=1; i<=n; i++)
        {
            adj[i].clear();
        }
    }
}