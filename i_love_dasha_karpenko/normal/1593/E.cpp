
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 4e5+7;
int depth[N],n,k,res;
vector<int> G[N];
void calc(int v,int par){
    depth[v] = 1;
    for(int to:G[v]){
        if (to==par)
            continue;
        calc(to,v);
        depth[v] = max(depth[v],depth[to]+1);
    }
}
void solve(int v,int par){
    set<pair<int,int> > S;
    for(int to:G[v]){
        S.insert({depth[to],to});
    }
    if (!S.empty()) {
        pair<int, int> mx = *S.rbegin();
        S.erase(*S.rbegin());
        if (!S.empty())
            depth[v] = S.rbegin()->first + 1;
        else depth[v] = 1;
        S.insert(mx);
    }
    else depth[v] = 1;
    if (depth[v]>k)
        ++res;
    for(int to:G[v]){
        if (to==par)
            continue;
        int o1 = depth[v],o2 = depth[to];
        S.erase({depth[to],to});
        if (!S.empty())
            depth[v] = S.rbegin()->first+1;
        else depth[v] = 1;
        solve(to,v);
        depth[to] = o2;
        depth[v] = o1;
        S.insert({depth[to],to});
    }
}
void solve(){

    cin>>n>>k;
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    calc(1,1);
    res = 0;
    solve(1,1);
    cout<<res<<endl;
    for(int i = 1;i<=n;++i){
        G[i].clear();
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();


    return 0;
}