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

const ll maxn=3e5+30;
const ll mod=1e9+7;
const ll base=3e18;

/// you will be the best but now you just are trash
/// goal 3/7

vector<ll> adj[maxn];
ll mx[maxn];
ll val[maxn];
ll ans=base;
ll mxall=0;
ll a[maxn];
vector<pll> f[maxn];

void dfs(ll u,ll par)
{
    mxall=max(mxall,a[u]);
    for (auto to:adj[u])
    {
        if (to==par) continue;
        dfs(to,u);
        val[u]+=val[to];
        mx[u]=max(mx[u],mx[to]);
    }
    if (mx[u]<a[u])
    {
        val[u]+=(a[u]-mx[u]);
        mx[u]=a[u];
    }
}
pll mer(pll a,pll b)
{
    pll ans=make_pair(0,0);
    ans.ff=max(a.ff,b.ff);
    ans.ss=a.ss+b.ss;
    return ans;
}
void dfs1(ll u,ll par,ll mxpre,ll valpre)
{
    ll mxnw=0;
    ll valnw=0;
    for (auto to:adj[u])
    {
        if (to==par) continue;
        mxnw=max(mxnw,mx[to]);
        valnw+=val[to];
    }
    ll kc=max(0ll,a[u]-max(mxpre,mxnw));
    ans=min(ans,kc+valnw+valpre+mxall);
    /*if (kc+valnw+valpre+mxall==2)
    {
        cout <<u<<" "<<par<<" "<<mxpre<<" "<<valpre<<" "<<mxnw<<" "<<valnw<<endl;
    }*/
    f[u]=vector<pll> (adj[u].size(),make_pair(0,0));
    for (int i=adj[u].size()-1;i>=0;i--)
    {
        if (i+1<f[u].size()) f[u][i]=f[u][i+1];
        ll to=adj[u][i];
        if (to==par) continue;
        f[u][i]=mer(f[u][i],make_pair(mx[to],val[to]));
    }
    pll pre=make_pair(mxpre,valpre);
    for (int i=0;i<adj[u].size();i++)
    {
        if (adj[u][i]==par) continue;
        pll nw=pre;
        if (i+1<f[u].size())
        {
            nw=mer(nw,f[u][i+1]);
        }
        if (nw.ff<a[u]) nw.ss+=(a[u]-nw.ff),nw.ff=a[u];
        ll to=adj[u][i];
        dfs1(to,u,nw.ff,nw.ss);
        pre=mer(pre,make_pair(mx[to],val[to]));
    }
}

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
    ll n;
    cin>> n;
    for (int i=1;i<=n;i++)
    {
        cin>> a[i];
    }
    for (int i=1;i<=n-1;i++)
    {
        ll x, y;
        cin>>x>> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0);
    dfs1(1,0,0,0);
    cout <<ans<<endl;
}