#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MAXN = 10E5;
ll n,m,vis[DIM],depth[DIM],sq,P[DIM],taken[DIM];
vector<ll> G[DIM];
vector<ll> ans;
void dfs(ll v,ll par){
    P[v] = par;
    depth[v] = depth[par]+1;
    vis[v] = 1;
    for(ll to:G[v]){
        if (vis[to]==0 || to==par)continue;
        if (depth[v]-depth[to]+1>=sq){
            cout<<2<<endl;
            cout<<depth[v]-depth[to]+1<<endl;
            cout<<v<<' ';
            while(1){
                v = P[v];
                cout<<v<<' ';
                if (v==to)break;
            }
            exit(0);
        }
    }
    for(ll to:G[v]){
        if (vis[to]==0)
        dfs(to,v);
    }
}
void solve(ll v,ll par){
    P[v] = par;
    depth[v] = depth[par]+1;
    vis[v] = 1;

    for(ll to:G[v]){
        if (vis[to]==0)
        solve(to,v);
    }
    if (taken[v]==0){
        for(ll to:G[v]){
            taken[to] = 1;
        }
        ans.pb(v);
    }
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sq = sqrt(n);
    if (sq*sq<n)sq++;
    forn(i,m){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    depth[1] = 0;
    dfs(1,1);
    memset(vis,0,sizeof(vis));
    memset(depth,0,sizeof(depth));
    memset(P,0,sizeof(P));
    solve(1,1);
    cout<<1<<endl;
    for(ll i = 0;i<sq;i++)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}
// a[i]-b[i]>b[j]-a[j]