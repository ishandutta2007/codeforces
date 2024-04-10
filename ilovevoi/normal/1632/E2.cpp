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

const ll maxn=3e5+100;
const ll mod=1e9+7 ;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 2/7

vector<ll> adj[maxn];
pll mx;
multiset<ll,greater<ll>> st;
ll dep[maxn];
ll anc[maxn][20];
ll lca(ll x,ll y)
{
    if (dep[x]<dep[y]) swap(x,y);
    ll kc=dep[x]-dep[y];
    for (int i=19;i>=0;i--) if (kc&(1ll<<i)) x=anc[x][i];
    if (x==y) return x;
    for (int i=19;i>=0;i--) if (anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}
vector<ll> vt[maxn];
void add(ll u)
{
    st.insert(dep[u]+dep[mx.ss]-2*dep[lca(u,mx.ss)]);
}
void ers(ll u)
{
    auto it=st.lower_bound(dep[u]+dep[mx.ss]-2*dep[lca(u,mx.ss)]);
    st.erase(it);
}
void dfs(ll u,ll par)
{
    anc[u][0]=par;
    for (int i=1;i<20;i++) anc[u][i]=anc[anc[u][i-1]][i-1];
    mx=max(mx,make_pair(dep[u],u));
    vt[dep[u]].pb(u);
    for (auto to:adj[u])
    {
        if (to==par) continue;
        dep[to]=dep[u]+1;
        dfs(to,u);
    }
}
ll res[maxn];

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
        ll n;
        cin>> n;
        for (int i=1;i<=n-1;i++)
        {
            ll x, y;
            cin>>x>> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        mx=make_pair(-1,0);
        dfs(1,0);
        for (int i=1;i<=n;i++) res[i]=base;
        for (int i=2;i<=n;i++) add(i);
        res[n]=min(res[n],mx.ff);
   //     cout <<res[n]<<endl;
        for (ll i=1;i<=n;i++)
        {
            for (auto to:vt[i]) ers(to);
            if (st.size())
            {
                auto p=(*st.begin());
                ll mx=(p+1)/2;
               // cout <<mx<<" "<<i<<endl;
                if (mx<=i)
                {
                    res[i-mx]=min(res[i-mx],i);
                }
            }
        }
        for (int i=n-1;i>=1;i--)
        {
            res[i]=min(res[i],res[i+1]);
        }
        F(i,1,n) cout <<res[i]<<" ";
        cout <<endl;
        F(i,0,n) vt[i].clear(),adj[i].clear();
        st.clear();
    }
}