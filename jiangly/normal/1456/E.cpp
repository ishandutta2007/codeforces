#include <bits/stdc++.h>

constexpr int N = 52;

int64_t dp[N + 1][N][N][2][2], g[N][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    k += 2;
    std::vector<int64_t> L(n), R(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> L[i] >> R[i];
        L[i] = 2 * L[i];
        R[i] = 2 * R[i] + 2;
    }
    
    std::vector<int64_t> c(k);
    for (int i = 1; i < k - 1; ++i) std::cin >> c[i];
    
    std::memset(dp, 0x1f, sizeof(dp));
    
    for (int i = 0; i <= n; ++i)
        for (int x = 0; x < 2; ++x)
            for (int y = 0; y < 2; ++y) dp[k][i][i][x][y] = 0;
    
    for (int d = k - 1; d >= 0; --d) {
        for (int l = 0; l <= n; ++l) {
            for (int x = 0; x < 2; ++x) {
                std::memset(g, 0x3f, sizeof(g));
                if (l == 0) g[l][0] = g[l][1] = 0;
                else g[l][x] = 0;
                for (int r = l; r <= n; ++r) {
                    for (int y = 0; y < 2; ++y) {
                        for (int mid = l; mid <= r; ++mid) {
                            for (int z = 0; z < 2; ++z) {
                                int dl = (mid == 0 ? z : ((z == 0 ? L[mid - 1] : R[mid - 1]) >> d & 1) ^ (l != mid));
                                int dr = (r == n ? dl : ((y == 0 ? L[r] : R[r]) >> d & 1));
                                dp[d][l][r][x][y] = std::min(dp[d][l][r][x][y], g[mid][z] + c[d] * (dl ^ dr) + dp[d + 1][mid][r][z][y]);
                                if (r < n) {
                                    if (((L[r] ^ R[r]) >> (d + 1)) == 0) continue;
                                    if (y == 0 && (L[r] >> d & 1) == 1) continue;
                                    if (y == 1 && (R[r] >> d & 1) == 0) continue;
                                    dr = ((y == 0 ? L[r] : R[r]) >> d & 1) ^ 1;
                                    g[r + 1][y] = std::min(g[r + 1][y], g[mid][z] + c[d] * (dl ^ dr) + dp[d + 1][mid][r][z][y]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << dp[0][0][n][0][0] << "\n";
    
    return 0;
}