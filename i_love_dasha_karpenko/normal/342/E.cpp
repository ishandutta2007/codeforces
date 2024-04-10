#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 10E4+7;
const ll INF = 10E17;
const ll LOG = 18;
ll cent = -1;
ll n,m,sz[DIM],level[DIM],P[DIM][LOG],D[DIM],tin[DIM],tout[DIM],timer = 0,dist[DIM],cp[DIM];
vector<ll> G[DIM];
void calcsize(ll v,ll par){
    sz[v] = 1;
    for(ll to:G[v]){
        if (level[to]==0 && to!=par){
            calcsize(to,v);
            sz[v]+=sz[to];
        }
    }
}
ll findcent(ll v,ll par,ll compsize){
    for(ll to:G[v]){
        if (level[to]==0 && to!=par && sz[to]*2>compsize)return findcent(to,v,compsize);
    }
    return v;
}
void decompose(ll v,ll par,ll lev){
    calcsize(v,-1);
    ll cs = sz[v];
    ll cent = findcent(v,-1,cs);
    level[cent] = lev;
    cp[cent] = par;
    for(ll to:G[cent]){
        if (level[to]==0)decompose(to,cent,lev+1);
    }
}
void dfs(ll v,ll par){
    tin[v] = ++timer;
    P[v][0] = par;
    ll x =par;
    if (x==-1)x = v;
    for(ll i = 1;i<LOG;i++){
        P[v][i] = P[x][i-1];
        x = P[v][i];
    }
    for(ll to:G[v])
        if (to!=par){
            dist[to] = dist[v]+1;
            dfs(to,v);
        }

    tout[v] = ++timer;
}
ll ip(ll a,ll b){
    if (a==0)return 1;
    if (tin[a]<=tin[b] && tout[b]<=tout[a])return 1;
    return 0;
}
ll lca(ll a,ll b){
    if (ip(a,b))return a;
    if (ip(b,a))return b;
    for(ll i = LOG-1;i>=0;i--){
        if (!ip(P[a][i],b))a = P[a][i];
    }
    a = P[a][0];
    return a;
}
ll di(ll a,ll b){
    ll lc = lca(a,b);
    return dist[a]+dist[b]-dist[lc]*2;
}
void paint(ll v){
    ll x = v;
    while(level[x]!=0){
        if (D[x]==-1)D[x] = di(x,v);
        else
            D[x] = min(D[x],di(x,v));
        x = cp[x];
    }
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    decompose(1,-1,1);
    dfs(1,-1);
    memset(D,-1,sizeof(D));
    paint(1);
    //cout<<di(2,2)<<endl;
    forn(qe,m){

        ll t,v;
        cin>>t>>v;
        if(t==1){
            paint(v);
        }
        else{
            ll x = v;
            ll res = INF;
            while(level[x]!=0){
                if (D[x]!=-1)res = min(res,D[x]+di(v,x));
                x = cp[x];
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
// 9 7+2