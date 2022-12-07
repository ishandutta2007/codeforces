#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000005;

int n, m, dp[N];
vector<int> g[N];
long long ans;

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v > u) continue;
        dp[u] = max(dp[u], dfs(v) + 1);
    }
    return dp[u];
}

int main() {
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1LL * dfs(i) * (int)g[i].size());
    }
    printf("%lld\n", ans);
    return 0;
}