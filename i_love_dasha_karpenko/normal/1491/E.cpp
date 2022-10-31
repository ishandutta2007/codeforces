//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 2E5+7;
set<ll> G[DIM];
ll sz[DIM],fib[DIM];

void dfs(ll v,ll par){
    sz[v] = 1;
    for(ll to:G[v]){
        if (to==par)continue;
        dfs(to,v);
        sz[v]+=sz[to];
    }
}
pair<ll,ll> divide(ll v,ll par,ll need){
    for(ll to:G[v]){
        if (sz[to]==need)return {v,to};
    }
    for(ll to:G[v]){
        if (to==par)continue;
        ll p1 = sz[v],p2 = sz[to];
        sz[v]-=sz[to];
        sz[to]+=sz[v];
        pair<ll,ll> ret = divide(to,v,need);
        if (ret.first!=0)
            return ret;
        sz[v] = p1;
        sz[to] = p2;
    }
    return {0,0};
}
ll solve(ll root,ll order){
    dfs(root,root);
    if (sz[root]==1)return 1;
    if (sz[root]!=fib[order])return 0;
    pair<ll,ll> edge = divide(root,root,fib[order-2]);
    if (edge.first==0)
        return 0;
    G[edge.first].erase(edge.second);
    G[edge.second].erase(edge.first);
    return solve(edge.first,order-1)*solve(edge.second,order-2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for(ll i = 1;i<n;++i){
        ll u,v;
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
    }
    ll ptr = 2;
    fib[1] = fib[2] = 1;
    while(fib[ptr]<n){
        ++ptr;
        fib[ptr] = fib[ptr-1]+fib[ptr-2];
    }
    if (solve(1,ptr))
        cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}