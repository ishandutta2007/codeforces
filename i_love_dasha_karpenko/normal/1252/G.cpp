#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 1e9;

ll n,k,sz[DIM];
ll dp[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par,ll depth){
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v,depth+1);
        sz[v]+=sz[to];
    }
    dp[v] = depth-sz[v];
    sz[v]++;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,1,0);
    sort(dp+1,dp+1+n,greater<ll>());
    ll res = 0;
    forn(i,k)res+=dp[i];
    cout<<res<<endl;
    return 0;
}