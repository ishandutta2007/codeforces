#include <iostream>
#include <algorithm>
#include <vector>
constexpr int N = 1'000, M = 200'000;
int n, m, q;
int dp[N][N], u[M], v[M], s[M], t[M], r[M];
std::vector<int> o[M];
bool ans[M];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i];
        --u[i];
        --v[i];
    }
    for (int i = 0; i < q; ++i) {
        int l;
        std::cin >> l >> r[i] >> s[i] >> t[i];
        --s[i];
        --t[i];
        --l;
        o[l].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        std::fill(dp[i], dp[i] + n, m);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j)
            dp[j][j] = i;
        for (int j = 0; j < n; ++j)
            dp[u[i]][j] = dp[v[i]][j] = std::min(dp[u[i]][j], dp[v[i]][j]);
        for (int j : o[i])
            if (dp[s[j]][t[j]] < r[j])
                ans[j] = true;
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}