#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 2E5+7;

const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll LOG = 21;
vector<pp> G[DIM];
pp P[DIM][LOG];
ll tin[DIM],tout[DIM],timer = 0;
void dfs(ll v,ll par,ll edg = 0){
    P[v][0] = {par,edg};
    tin[v] = ++timer;
    for(ll i = 1;i<LOG;++i){
        P[v][i].fi = P[P[v][i-1].fi][i-1].fi;
        P[v][i].sc = max(P[P[v][i-1].fi][i-1].sc,P[v][i-1].sc);
    }
    for(pp to:G[v]){
        if (to.fi==par)continue;
        dfs(to.fi,v,to.sc);
    }
    tout[v] = timer;
}
ll ip(ll a,ll b){
    if (tin[a]<=tin[b] && tout[a]>=tout[b])return 1;
    return 0;
}
ll fm(ll a,ll b){
    if (a==b)return 0;
    ll res = 0;
    for(ll i = LOG-1;i>=0;--i){
        if (!ip(P[b][i].fi,a)){
            res = max(res,P[b][i].sc);
            b = P[b][i].fi;
        }
    }
    return max(res,P[b][0].sc);
}
ll lca(ll a,ll b){
    if (ip(a,b))return a;
    if (ip(b,a))return b;
    for(ll i = LOG-1;i>=0;--i){
        if (!ip(P[a][i].fi,b))a = P[a][i].fi;
    }
    return P[a][0].fi;
}
ll query(ll a,ll b){
    ll lc = lca(a,b);
    return max(fm(lc,a),fm(lc,b));
}
ll cc[DIM],t[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,m;
    cin>>n>>m;
    forn(i,n)cin>>t[i];
    forn(i,m-1){
        ll a,b;
        cin>>a>>b;
        G[a].pb({b,i});
        G[b].pb({a,i});
    }
    dfs(1,1);
    forn(i,n-1){
        cc[query(t[i],t[i+1])]++;
    }
    ll res = n-1;
    for(ll i = 0;i<m;++i){
        res-=cc[i];
        cout<<res<<endl;
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,