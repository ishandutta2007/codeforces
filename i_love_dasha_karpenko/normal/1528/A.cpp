//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//#define endl '\n'
const ll DIM = 1E5+7;
ll L[DIM],R[DIM],dp[DIM][2];
vector<ll> G[DIM];
void dfs(ll v,ll par){
    dp[v][0] = dp[v][1] = 0;
    for(ll to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
        dp[v][0]+=max(abs(L[v]-L[to])+dp[to][0],abs(L[v]-R[to])+dp[to][1]);
        dp[v][1]+=max(abs(R[v]-L[to])+dp[to][0],abs(R[v]-R[to])+dp[to][1]);
    }
}
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i){
        cin>>L[i]>>R[i];
        G[i].clear();
    }
    for(ll i = 1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    cout<<max(dp[1][0],dp[1][1])<<endl;

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}