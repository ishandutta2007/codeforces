#include <bits/stdc++.h>

const int K = 45;
const int N = 100005;

int n, k, l, x, y;
int val[N], ans[N];

int dp[N][K], up[N][K], c[N][K];

std::vector<int> to[N];

inline void dfs1(int u, int f) {
    for (int v : to[u]) {
        if (v == f) continue;
        dfs1(v, u);
        for (int i = 0; i < l; ++i) dp[u][i + 1] ^= dp[v][i];
    }
    dp[u][0] = dp[u][l], dp[u][l] = 0, dp[u][1] ^= val[u];
}

inline void build(int u, int f) {
    for (int i = 0; i < l; ++i) {
        up[u][i] = dp[f][i] ^ dp[u][(i + l - 1) % l] ^ up[f][(i + l - 1) % l];
    }
}

inline void dfs2(int u, int f) {
    if (u != 1) build(u, f);
    for (int i = k; i < l; ++i) ans[u] ^= up[u][i];
    for (int v : to[u]) {
        if (v == f) continue;
        dfs2(v, u);
        for (int i = k; i < l; ++i) ans[u] ^= dp[v][i];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k, l = k << 1;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        to[x].push_back(y), to[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) std::cin >> val[i];
    dfs1(1, 1), dfs2(1, 1);
    // for (int u = 1; u <= n; ++u) {
    //     for (int i = 0; i < l; ++i) std::cout << dp[u][i] << ' ';
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // for (int u = 1; u <= n; ++u) {
    //     for (int i = 0; i < l; ++i) std::cout << up[u][i] << ' ';
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    for (int i = 1; i <= n; ++i) std::cout << int(bool(ans[i])) << ' ';
    std::cout << std::endl;
    return 0;
}