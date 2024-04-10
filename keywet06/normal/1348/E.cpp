#include <bits/stdc++.h>

const int N = 505;

using int64 = long long;

int n, m, i, j, k, a, b;
int D[N][N];

int64 sa, sb;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    D[0][0] = 1;
    for (i = 1; i <= n; ++i) {
        std::cin >> a >> b;
        sa += a, sb += b;
        for (j = 0; j <= std::min(m + m, a); ++j) {
            if ((a - j + m - 1) / m == (a - j + b + m) / m) continue;
            for (k = 0; k < m; ++k) {
                if (D[i - 1][k]) D[i][(k + j) % m] = 1;
            }
        }
    }
    int64 res = 0;
    for (i = 0; i < m; ++i) {
        if (!D[n][i]) continue;
        int z = (sa + sb - i) % m;
        res = std::max(res, (sa + sb - z - i) / m);
    }
    std::cout << res << std::endl;
    return 0;
}