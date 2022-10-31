#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less_equal<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

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
const ll M1 = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
vector<pp> G[DIM];
ll A[DIM],sz[DIM];
pp cnt[DIM];
ll val[DIM];
ll n,m;

void dfs(ll v,ll par){
    sz[v] = 1;
    for(pp to:G[v]){
        if (to.fi==par)continue;
        dfs(to.fi,v);
        sz[v]+=sz[to.fi];
        cnt[to.sc].fi = (sz[to.fi]*(n-sz[to.fi]));
    }
}
ll res = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n;
        forn(i,n-1){
            ll u,v;
            cin>>u>>v;
            G[u].pb({v,i});
            G[v].pb({u,i});
            cnt[i].sc = i;
        }
        dfs(1,1);
        sort(cnt+1,cnt+n);

        cin>>m;
        forn(i,m)cin>>A[i];
        for(ll i = m+1;i<=n-1;++i)A[i] = 1;
        m = max(m,n-1);
        sort(A+1,A+1+m);
        ll r = 1;
        for(ll i = n-1;i<=m;++i)r = (r*A[i])%MOD;
        A[n-1] = r;
        res = 0;

        forn(i,n-1){
           res = (res+cnt[i].fi*A[i])%MOD;
        }

        cout<<res<<endl;
        forn(i,n)G[i].clear();
    }
    return 0;
}