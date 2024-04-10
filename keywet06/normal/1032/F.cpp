#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int C = 3;
const int N = 300005;

int n, v, u;
int used[N];

int64 dp[N][C];

std::vector<int> g[N];

int64 inv(int64 x) {
    int64 k = P - 2, ret = 1;
    while (k) {
        if (k & 1) ret = (ret * x) % P;
        k /= 2, x = (x * x) % P;
    }
    return ret;
}

void dfs(int v) {
    dp[v][2] = 1;
    int u;
    int64 p = 1, x;
    for (int i = 0; i < g[v].size(); ++i) {
        u = g[v][i];
        if (used[u] != -1) continue;
        used[u] = v;
        dfs(u);
        dp[v][2] = (dp[v][2] * dp[u][2]) % P;
        p = (p * (dp[u][0] + dp[u][2])) % P;
    }
    dp[v][1] = p;
    for (int i = 0; i < g[v].size(); ++i) {
        u = g[v][i];
        if (used[u] != v) continue;
        x = inv((dp[u][0] + dp[u][2]) % P);
        dp[v][0] = (dp[v][0] + (dp[u][1] * ((p * x) % P)) % P) % P;
    }
    dp[v][2] = (dp[v][0] + dp[v][2]) % P;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) used[i] = -1;
    used[0] = 0, dfs(0);
    std::cout << dp[0][2] << '\n';
    return 0;
}