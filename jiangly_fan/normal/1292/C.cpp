#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 3200;
vector<int> G[maxn];
int d[maxn][maxn], pa[maxn][maxn], sz[maxn][maxn], n;
vector<pair<int, int>> p[maxn];
LL dp[maxn][maxn];
LL ans;
void DFS(int s, int u){
    sz[s][u] = 1;
    for(int v : G[u]) if(v != pa[s][u]){
        pa[s][v] = u;
        d[s][v] = d[s][u] + 1;
        DFS(s, v);
        sz[s][u] += sz[s][v];
    }
}
void fuck(int s){
    DFS(s, s);
}
void fuck(int u, int v){
    ans = max(ans, dp[u][v] += sz[v][u] * sz[u][v]);
    int x = pa[u][v];
    if(x > u) dp[u][x] = max(dp[u][x], dp[u][v]);
    else dp[x][u] = max(dp[x][u], dp[u][v]);
    x = pa[v][u];
    if(x > v) dp[v][x] = max(dp[v][x], dp[u][v]);
    else dp[x][v] = max(dp[x][v], dp[u][v]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i += 1){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i += 1) fuck(i);
    for(int i = 1; i <= n; i += 1)
        for(int j = i + 1; j <= n; j += 1) p[d[i][j]].push_back({i, j});
    for(int i = n; i; i -= 1) for(auto pp : p[i]) fuck(pp.first, pp.second);
    cout << ans;
    return 0;
}