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
//#define endl '\n'
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
ll dp[DIM];
vector<ll> G[DIM];
ll A[DIM];
ll dfs(ll v,ll par,ll st = 0){
    ll fl = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        ll x = dfs(to,v);

        if (x!=0){
            fl = 1;
            swap(A[x],A[v]);
        }
        dp[v]+=dp[to];
    }
    if (fl==0)dp[v]+=2;
    if (fl==0 && st==1){
        swap(A[v],A[G[v][0]]);
    }
    else if (fl==0)return v;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;forn(i,n)A[i] = i;
    forn(i,n-1){
        ll u,v;
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1,1,1);
    cout<<dp[1]<<endl;
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}