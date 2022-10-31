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
const ll DIM = 1E5+7;
const ll INF = 1E18;
const ll LOG = 21;
vector<ll> G[DIM];
ll depth[DIM],P[DIM][LOG],tin[DIM],tout[DIM],timer = 0,pos[DIM];
void dfs(ll v){
    tin[v] = ++timer;
    pos[timer] = v;
    for(ll i = 1;i<LOG;++i){
        P[v][i] = P[P[v][i-1]][i-1];
    }
    for(ll to:G[v]){
        P[to][0] = v;
        depth[to] = depth[v]+1;
        dfs(to);
    }
    tout[v] = timer;
}
vector<ll> T[DIM*4];
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t].pb(depth[pos[tl]]);
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    merge(T[t*2+1].begin(),T[t*2+1].end(),T[t*2+2].begin(),T[t*2+2].end(),back_inserter(T[t]));
}
ll query(ll t,ll tl,ll tr,ll l,ll r,ll val){
    if (tl>r || l>tr)return 0;
    if (l<=tl && tr<=r){
        auto it = equal_range(T[t].begin(),T[t].end(),val);
        return (it.sc-it.fi);
    }
    ll tm = (tl+tr)/2;
    return query(t*2+1,tl,tm,l,r,val)+query(t*2+2,tm+1,tr,l,r,val);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> roots;
    forn(i,n){
        ll x;
        cin>>x;
        if (x==0)roots.pb(i);
        else {
            G[x].pb(i);
        }
    }
    for(ll root:roots){
        P[root][0] = root;
        dfs(root);
    }
    buildtree(0,1,n);
    ll m;
    cin>>m;
    while(m--){
        ll v,p;
        cin>>v>>p;
        ll dep = depth[v];
        if (dep-p<0){
            cout<<0<<' ';
            continue;
        }
        for(ll i = LOG-1;i>=0;--i){
            if (dep-depth[P[v][i]]<=p)v = P[v][i];
        }
        cout<<query(0,1,n,tin[v],tout[v],dep)-1ll<<' ';
    }
    return 0;
}