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
const ll DIM = 3E5+7;
const ll INF = 1E9;
const ll MOD = 998244353;
ll dp1[DIM],dp2[DIM],dp3[DIM];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    dp1[v] = dp2[v] = dp3[v] = 1;
    ll flag = 0;
    ll sum1 = 1;
    ll sum2 = 1;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        flag = 1;
        sum1 = (sum1*(dp1[to]+dp2[to]+dp3[to]))%MOD;

        dp1[v] = (dp1[v]*(dp1[to]+dp2[to]*2+dp3[to]*2))%MOD;
        dp2[v] = (dp2[v]*(dp2[to]*2+dp3[to]*3+dp1[to]*2))%MOD;
        dp3[v] = (dp3[v]*(dp3[to]+dp2[to]+dp1[to]))%MOD;

    }
    dp1[v] = (dp1[v]-sum1+MOD)%MOD;
    dp2[v] =  (dp2[v]-sum1+MOD)%MOD;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n-1){
        ll x,y;
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,1);

    cout<<(dp1[1]+dp2[1]+dp3[1]-1+MOD)%MOD<<endl;
    return 0;
}