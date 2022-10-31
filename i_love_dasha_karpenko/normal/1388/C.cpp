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

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 1E5;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll n,m,H[DIM],P[DIM],sz[DIM];
vector<ll> G[DIM];
ll flag = 0;

void dfs(ll v,ll par){
    pp cur = {0,0};
    sz[v] = P[v];
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        sz[v]+=sz[to];
        ll base = (sz[to]-abs(H[to]));

        cur.fi+=base;
        cur.sc+=base;
        if (H[to]<0)cur.sc+=-H[to];
        else cur.fi+=H[to];
    }
    if (cur.fi-cur.sc>H[v]+P[v] || abs(H[v])>sz[v] || (sz[v]-abs(H[v]))%2 ){
        flag = 1;
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){

        cin>>n>>m;
        forn(i,n){
            cin>>P[i];
        }
        forn(i,n)cin>>H[i];
        forn(i,n-1){
            ll u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        flag = 0;
        dfs(1,1);

        if (flag)cout<<"NO\n";
        else cout<<"YES\n";
        forn(i,n){
            H[i] = P[i] = sz[i] = 0;
            G[i].clear();
        }
    }

    return 0;
}