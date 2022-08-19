#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(1 << 9));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << 9); ++j) {
            if (!dp[i][j])
                continue;
            for (int k = 0; k < m; ++k)
                dp[i + 1][j | (a[i] & b[k])] = 1;
        }
    }
    int x = 0;
    while (!dp[n][x])
        ++x;
    std::cout << x << "\n";
    return 0;
}