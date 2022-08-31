#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <deque>
#include <tuple>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> d(m);
    for (int i = 0; i < m; ++i)
        std::cin >> d[i];
    std::sort(d.begin(), d.end());
    int g, r;
    std::cin >> g >> r;
    std::vector<std::vector<int>> dp(m, std::vector<int>(g + 1, -1));
    std::deque<std::tuple<int, int, int>> que;
    que.emplace_back(0, 0, 0);
    while (!que.empty()) {
        auto [u, t, f] = que.front();
        que.pop_front();
        if (dp[u][t] != -1)
            continue;
        dp[u][t] = f;
        if (t == g)
            que.emplace_back(u, 0, f + 1);
        if (u != 0 && t + d[u] - d[u - 1] <= g)
            que.emplace_front(u - 1, t + d[u] - d[u - 1], f);
        if (u != m - 1 && t + d[u + 1] - d[u] <= g)
            que.emplace_front(u + 1, t + d[u + 1] - d[u], f);
    }
    long long ans = -1;
    for (int i = 0; i <= g; ++i)
        if (dp[m - 1][i] != -1 && (ans == -1 || ans > 1ll * (g + r) * dp[m - 1][i] + i))
            ans = 1ll * (g + r) * dp[m - 1][i] + i;
    std::cout << ans << "\n";
    return 0;
}