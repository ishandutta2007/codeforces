#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, P;
    std::cin >> n >> m >> P;
    
    std::vector<std::vector<int>> C(m + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
    
    std::vector<int> ways(m + 1), sum(m + 1);
    ways[0] = 1;
    sum[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < i; ++j) {
            int cways = C[i - 1][j];
            ways[i] = (ways[i] + int64_t(cways) * ways[j] % P * ways[i - j - 1] % P * (i + 1)) % P;
            sum[i] = (sum[i] + ((int64_t(ways[j]) * sum[i - j - 1] + int64_t(ways[i - j - 1]) * sum[j]) % P * (i + 1) + int64_t(j * (j + 1) / 2 + (i - j) * (i - j - 1) / 2) * ways[j] % P * ways[i - j - 1]) % P * cways) % P;
        }
    }
    
    ++n;
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1)), g(f);
    f[0][0] = 1;
    g[0][0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; j + k <= m && i + k + 1 <= n; ++k) {
                int cways = C[j + k][j];
                f[i + k + 1][j + k] = (f[i + k + 1][j + k] + int64_t(f[i][j]) * ways[k] % P * cways) % P;
                g[i + k + 1][j + k] = (g[i + k + 1][j + k] + (int64_t(f[i][j]) * sum[k] + int64_t(g[i][j]) * ways[k]) % P * cways) % P;
            }
        }
    }
    
    std::cout << g[n][m] << "\n";
    
    return 0;
}