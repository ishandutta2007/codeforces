#include <bits/stdc++.h>

constexpr int P = 1000000007;

int sum[1001][1001];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, r;
    std::cin >> n >> m >> r;
    std::vector<int> x(n), y(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> b[i];
        ++sum[x[i]][y[i]];
    }
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j) sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    std::vector<std::vector<int>> C(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    int ans = 0;
    auto count = [&](int l, int r, int u, int d) {
        if (l > r || u > d) return 0;
        l = std::max(l, 1);
        r = std::min(r, 1000);
        u = std::max(u, 1);
        d = std::min(d, 1000);
        return sum[r][d] - sum[l - 1][d] - sum[r][u - 1] + sum[l - 1][u - 1];
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val = 1ll * b[i] * b[j] % P;
            int ways = C[n][m];
            int num = n - count(x[i] - r, x[i] + r, y[i] - r, y[i] + r);
            ways = (ways - C[num][m] + P) % P;
            num = n - count(x[j] - r, x[j] + r, y[j] - r, y[j] + r);
            ways = (ways - C[num][m] + P) % P;
            num = n - count(x[i] - r, x[i] + r, y[i] - r, y[i] + r) - count(x[j] - r, x[j] + r, y[j] - r, y[j] + r);
            num += count(std::max(x[i], x[j]) - r, std::min(x[i], x[j]) + r, std::max(y[i], y[j]) - r, std::min(y[i], y[j]) + r);
            ways = (ways + C[num][m]) % P;
            ans = (ans + 1ll * ways * val) % P;
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}