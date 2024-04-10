/*#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
#define F(i,a,b) for(ll i=a;i<=b;i++)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e5+5;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 0/7

pll dp[maxn][2];
pll dp1[2];
ll n;
vector<ll> adj[maxn];
map<pair<pll,ll>,ll> mp;

void dfs(ll u,ll par)
{
    dp[u][0]=make_pair(0,0);
    dp[u][1]=make_pair(1,-(ll)adj[u].size());
    for (auto to:adj[u])
    {
        if (to==par) continue;
        dfs(to,u);
        for (int t=0;t<=1;t++)
        {
            dp1[t]=dp[u][t];
            dp[u][t]=make_pair(-base,0);
        }
        for (int t=0;t<=1;t++)
        {
            for (int t1=0;t1<=1;t1++)
            {
                if (t&&t1) continue;
                dp[u][t]=max(dp[u][t],make_pair(dp1[t].ff+dp[to][t1].ff,dp1[t].ss+dp[to][t1].ss));
                if (dp[u][t]==make_pair(dp1[t].ff+dp[to][t1].ff,dp1[t].ss+dp[to][t1].ss))
                {
                    mp[make_pair(make_pair(u,to),t)]=t1;
                }
            }
        }
    }
}
ll w[maxn];
ll ans=0;
ll res=0;
void dosth(ll u,ll par,ll t)
{
    ans+=(t==1);
    if (t==0) w[u]=1;
    else w[u]=adj[u].size();
    res+=w[u];
    for (auto to:adj[u])
    {
        if (to==par) continue;
        dosth(to,u,mp[make_pair(make_pair(u,to),t)]);
    }
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
    ll n;
    cin>>  n;
    ll root=-1;
    for (int i=1;i<=n-1;i++)
    {
        ll x, y;
        cin>>x>> y;
        adj[x].pb(y);
        adj[y].pb(x);
        if (adj[x].size()>=2)
        {
            root=x;
        }
        if (adj[y].size()>=2) root=y;
    }
    if (n==2)
    {
        cout <<2<<" "<<2<<endl;
        cout <<1<<" "<<1<<endl;
        return 0;
    }
    dfs(root,0);
    if (dp[root][0]>dp[root][1])
    {
        dosth(root,0,0);
    }
    else
    {
        dosth(root,0,1);
    }
    cout <<ans<<" "<<res<<endl;
    for (int i=1;i<=n;i++) cout <<w[i]<<" ";
}