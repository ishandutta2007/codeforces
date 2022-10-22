#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 5;

int n, mx[MAXN], a[MAXN], sz[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    if (adj[u].empty()){
        sz[u] = 1;
        mx[u] = a[u];
        return ;
    }
    for (auto v : adj[u]){
        dfs(v);
        sz[u] += sz[v];
        mx[u] = max(mx[u], mx[v]);
        a[u] += a[v];
    }
    int z = a[u] - 1;
    if (z < 0){
        z = 0;
    }else{
        z = z / sz[u] + 1;
    }
    mx[u] = max(mx[u], z);
}

signed main(){
    cin >> n;
    for (int i = 2, p; i <= n; i++){
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dfs(1);
    cout << mx[1];
}