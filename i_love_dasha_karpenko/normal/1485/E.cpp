//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
const ll INF = 1E18;
const ll MOD = 1E9+7;
ll A[DIM],P[DIM],dp[DIM];
vector<ll> G[DIM];
vector<ll> V[DIM];
void dfs(ll v,ll par,ll level = 0){
    V[level].push_back(v);
    P[v] = par;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v,level+1);
    }
}
void solve(){
    ll n;
    cin>>n;
    for(ll i = 2;i<=n;++i){
        ll u,v;
        cin>>u;
        v = i;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(ll i = 2;i<=n;++i)
        cin>>A[i];
    dfs(1,1);
    ll res = 0;
    for(ll level = 1;level<=n;++level){
        if (V[level].size()==0)break;
        ll mx = -INF ,mi = INF,a = -INF,b = -INF;
        for(ll to:V[level]){
            mi = min(mi,A[to]);
            mx = max(mx,A[to]);
            a = max(a,dp[P[to]]+A[to]);
            b = max(b,dp[P[to]]-A[to]);
        }
        for(ll to:V[level]){
            dp[to] = max({a-A[to],b+A[to],dp[P[to]]+A[to]-mi,dp[P[to]]+mx-A[to]});
            res = max(res,dp[to]);
        }
    }
    cout<<res<<endl;
    for(ll i = 0;i<=n;++i){
        V[i].clear();
        G[i].clear();
        dp[i] = P[i] = A[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}