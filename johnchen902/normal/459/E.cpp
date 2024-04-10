#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<int, int>> adj[300000];
vector<int> dp[300000];
int dfs(int u, int c) {
    auto rng = upper_bound(adj[u].begin(), adj[u].end(), make_pair(c, 999999));
    if(rng == adj[u].end()) return 0;
    int i = rng - adj[u].begin();
    if(dp[u][i] != -1) return dp[u][i];
    auto low = lower_bound(adj[u].begin(), adj[u].end(), make_pair(rng->first, 0));
    auto upp = lower_bound(adj[u].begin(), adj[u].end(), make_pair(rng->first, 999999));
    dp[u][i] = dfs(u, rng->first);
    for(auto j = low; j != upp; ++j)
        dp[u][i] = max(dp[u][i], 1 + dfs(j->second, j->first));
    return dp[u][i];
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;
        adj[u].push_back({w, v});
    }
    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        dp[i] = vector<int>(adj[i].size(), -1);
    }
    int maxi = 0;
    for(int i = 0; i < n; i++)
        maxi = max(maxi, dfs(i, 0));
    printf("%d\n", maxi);
}