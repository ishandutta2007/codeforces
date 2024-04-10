#include <bits/stdc++.h>

#define Deb std::cerr
#define Debug Deb << "Debug(" << __LINE__ << "): "

using int64 = long long;

const int P = 998244353;
const int N = 5005;

int n, k, x, y, f, up;
int md[N];

int64 ans, ret;
int64 dp[N][N];

std::vector<int> to[N];

inline int64 inv(int64 x) {
    if (x == 0) throw "Error: inv(0) is undefined.";
    ret = 1;
    while (x > 1) ret = ret * (P - P / x) % P, x = P % x;
    return ret;
}

inline void dfs(int u, int f) {
    std::vector<int> s;
    for (int v : to[u]) {
        if (v != f) s.push_back(v), dfs(v, u), md[u] = std::max(md[u], md[v]);
    }
    for (int i = 0; i <= k / 2; ++i) dp[u][i] = 1;
    for (int v : s) {
        for (int i = 0; i <= k / 2; ++i) dp[u][i] = dp[u][i] * dp[v][i] % P;
    }
    for (int v : s) {
        for (int i = k / 2 + 1; i <= md[v]; ++i) {
            dp[u][i] += (P + dp[v][i] - dp[v][i - 1]) * dp[u][k - i] % P *
                        inv(dp[v][k - i]) % P;
        }
    }
    for (int i = k / 2 + 1; i <= k; ++i) {
        dp[u][i] = (dp[u][i - 1] + dp[u][i]) % P;
    }
    // Debug << "dp[" << u << "] = {";
    // for (int i = 0; i <= k; ++i) Deb << dp[u][i] << ", ";
    // Deb << "...};" << std::endl;
    ret = dp[u][k];
    for (int i = k; i; --i) dp[u][i] = (dp[u][i - 1] + ret) % P;
    dp[u][0] = ret, md[u] += md[u] < k;
    // Debug << "dp[" << u << "] = {";
    // for (int i = 0; i <= k; ++i) Deb << dp[u][i] << ", ";
    // Deb << "...};" << std::endl;
    // Debug << "md[" << u << "] = " << md[u] << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    dfs(1, 1);
    std::cout << dp[1][0] << std::endl;
    return 0;
}