#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 2E5+7;
const ll INF = 1E18;
vector<ll> G[DIM];
ll dp[DIM],res = 0;
pair<ll,ll> mxx = {0,0};
void dfs(ll v,ll par){
    pair<ll,ll> mx = {0,0};
    ll mi = INF;
    ll cnt = 0;
    for(ll to:G[v]){
        if (to==par)continue;
        ++cnt;
        dfs(to,v);
        mx.second = max(dp[to]+1,mx.second);
        if (mx.second>mx.first)swap(mx.first,mx.second);
        mi = min(mi,dp[to]+1);
    }
    if (mi==INF)mi = 0;

    res = max(res,mx.second+1);
   // res = max(res,mx.first);
    if (v==1)
    res = max(res,mx.first);
    else res = max(res,mx.first+1);

    dp[v] = mi;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;

    while(t--){
        mxx = {0,0};
        res = 0;
        ll n;
        cin>>n;
        for(ll i = 1;i<n;++i){
            ll u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1);
        res = max(res,mxx.second+1);
        res = max(res,dp[1]);
        res = max(res,mxx.first);
        cout<<res<<endl;
        for(ll i = 1;i<=n;++i){
            G[i].clear();
            dp[i] = 0;
        }
    }
    return 0;
}