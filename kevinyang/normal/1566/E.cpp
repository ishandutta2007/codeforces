#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<bool>bud(mxn);
vector<bool>child(mxn);
vector<int>dp(mxn);
int totalchildren = 0;
void reset(int n){
    for(int i = 1; i<=n; i++){
        adj[i].clear();
        bud[i] = false;
        child[i] = false;
        dp[i] = 0;
    }
    totalchildren = 0;
}
void dfs1(int u, int p){
    int children = 0;
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        dfs1(nxt,u);
        children++;
    }
    if(children==0)totalchildren++;
}
void dfs(int u, int p){
    int children = 0;
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        children++;
        dfs(nxt,u);
        dp[u]+=dp[nxt];
    }
    if(children==0){
        dp[u] = 1;
        child[u] = true;
        return;
    }
    int child2 = 0; int bud2 = 0;
    for(int nxt: adj[u]){
        if(nxt==p)continue;
        if(child[nxt])child2++;
        if(bud[nxt])bud2++;
    }
    if(child2>0&&child2+bud2==children){
        bud[u] = true;
    }
    dp[u]-=bud2;
    if(bud2==children){
        child[u] = true;
        dp[u]++;
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i<n-1; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs1(1,0);
        dfs(1,0);
        cout << dp[1] << "\n";
        reset(n);
    }
    return 0;
}