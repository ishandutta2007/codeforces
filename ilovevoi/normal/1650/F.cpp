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


ll a[maxn];
vector<pair<pll,ll>> adj[maxn];
ll dp[maxn][102];
int par[maxn][102];
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
        for (int i=1;i<=n;i++)
        {
            cin>> a[i];
        }
        F(i,1,m)
        {
            ll id, x, p;
            cin>> id>> x>> p;
            adj[id].pb(make_pair(make_pair(x,p),i));
        }
        ll pre=0;
        bool chk=true;
        vector<ll> ans;
        for (int i=1;i<=n;i++)
        {
            ll cnt=0;
            ll id=i;
            for (int t=0;t<=adj[id].size();t++)
            {
                for (int h=0;h<=100;h++)
                {
                    dp[t][h]=base;
                }
            }
            dp[0][0]=0;
            for (int t=1;t<=adj[id].size();t++)
            {
                auto p=adj[id][t-1];
                for (int h=0;h<=100;h++)
                {
                    dp[t][h]=min(dp[t][h],dp[t-1][h]);
                    if (dp[t][h]==dp[t-1][h])
                    {
                        par[t][h]=h;
                    }
                    ll nxt=min((ll)100,h+p.ff.ss);
                    dp[t][nxt]=min(dp[t][nxt],dp[t-1][h]+p.ff.ff);
                    if (dp[t][nxt]==dp[t-1][h]+p.ff.ff)
                    {
                        par[t][nxt]=h;
                    }
                }
            }
            if (pre+dp[adj[id].size()][100]>a[i])
            {
                chk=false;
                break;
            }
           ll nw=100;
            for (int i=adj[id].size();i>=1;i--)
            {
                auto p=par[i][nw];
                if (p==nw)
                {

                }
                else
                {
                    ans.pb(adj[id][i-1].ss);
                    nw=p;
                }
            }
            pre+=dp[adj[id].size()][100];
        }
        if (chk)
        {

        cout <<ans.size()<<endl;
        for (auto to:ans) cout <<to<<" ";
        cout <<endl;
        }
        else
        {
            cout <<-1<<endl;
        }
        for (int i=0;i<=n;i++) adj[i].clear();
    }
}