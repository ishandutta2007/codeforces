#include <bits/stdc++.h>
void chk(int &a, int b) {
    a = std::max(a, b);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int nR, nG, nB;
    std::cin >> nR >> nG >> nB;
    std::vector<int> r(nR), g(nG), b(nB);
    for (int i = 0; i < nR; ++i)
        std::cin >> r[i];
    for (int i = 0; i < nG; ++i)
        std::cin >> g[i];
    for (int i = 0; i < nB; ++i)
        std::cin >> b[i];
    std::sort(r.begin(), r.end());
    std::sort(g.begin(), g.end());
    std::sort(b.begin(), b.end());
    int dp[201][201][201] = {};
    for (int i = 0; i <= nR; ++i) {
        for (int j = 0; j <= nG; ++j) {
            for (int k = 0; k <= nB; ++k) {
                if (i < nR)
                    chk(dp[i + 1][j][k], dp[i][j][k]);
                if (j < nG)
                    chk(dp[i][j + 1][k], dp[i][j][k]);
                if (k < nB)
                    chk(dp[i][j][k + 1], dp[i][j][k]);
                if (i < nR && j < nG)
                    chk(dp[i + 1][j + 1][k], dp[i][j][k] + r[i] * g[j]);
                if (i < nR && k < nB)
                    chk(dp[i + 1][j][k + 1], dp[i][j][k] + r[i] * b[k]);
                if (j < nG && k < nB)
                    chk(dp[i][j + 1][k + 1], dp[i][j][k] + g[j] * b[k]);
            }
        }
    }
    std::cout << dp[nR][nG][nB] << "\n";
    return 0;
}