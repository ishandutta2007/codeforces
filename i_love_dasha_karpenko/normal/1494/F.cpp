//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 3007;
ll vis[DIM],n,m,tr[DIM];
vector<pair<ll,ll> > G[DIM];
void con(ll v){
    for(auto to:G[v]){
        if (vis[to.second] || tr[to.second])
            continue;
        tr[to.second] = 1;
        con(to.first);
    }
}
ll Check(ll v){
    ll cnt = 0,flag = 0;
    for(ll i = 1;i<=n;++i){
        ll odd = 0;
        for(auto to:G[i]){
            if (vis[to.second]==0)odd^=1;
        }
        cnt+=odd;
        if (i==v && !odd)flag = 1;
    }
    if (cnt==0)flag = 0;
    ll start = 0;

    memset(tr,0,sizeof(tr));
    for(ll i = 1;i<=n;++i){
        for(auto to:G[i]) {
            if (!vis[to.second]) {
                start = i;
                break;
            }
        }
        if (start)break;
    }
    con(start);

    for(ll i = 1;i<=m;++i){
        if (tr[i]==0 && vis[i]==0)return 0;
    }
    return (cnt==2 || cnt==0) && !flag;
}
vector<ll> path;
void dfs(ll v){
    while(!G[v].empty()){
        auto to = G[v].back();
        G[v].pop_back();
        if (vis[to.second])continue;
        vis[to.second] = 1;
        dfs(to.first);
    }
    path.push_back(v);
}
void solve(ll start){
    vector<ll> vv;
    if (start!=0){
        vv.push_back(-1);
        for(auto to:G[start]){
            if (!vis[to.second])continue;
            vv.push_back(to.first);
            vv.push_back(start);
        }
    }
    if (start==0) {
        start = 1;
        for (ll i = 1; i <= n; ++i) {
            ll odd = 0;
            for (auto to:G[i]) {
                if (vis[to.second] == 0)odd ^= 1;
            }
            if (odd)
                start = i;
        }
    }
    dfs(start);
    for(ll to:vv)path.push_back(to);
    cout<<path.size()<<endl;
    for(ll to:path)cout<<to<<' ';
    cout<<endl;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(ll i = 1;i<=m;++i){
        ll u,v;
        cin>>u>>v;
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    if (Check(0)){
        solve(0);
    }
    for(ll i = 1;i<=n;++i){
        for(pair<ll,ll> to:G[i]){
            if (G[to.first].size()%2)
                vis[to.second] = 1;
        }
        for(pair<ll,ll> to:G[i]){
            vis[to.second] = 0;
            if (Check(i)){
                solve(i);
            }
            vis[to.second] = 1;
        }
        for(pair<ll,ll> to:G[i]){
            vis[to.second] = 0;
        }
    }
    cout<<"0\n";
    return 0;
}