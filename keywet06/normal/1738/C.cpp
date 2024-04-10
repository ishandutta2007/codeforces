#include <bits/stdc++.h>

using int64 = long long;

const int N = 105;

bool f[N][N][2][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    f[0][0][0][0] = f[0][0][1][0] = true;
    f[0][0][0][1] = f[0][0][1][1] = false;
    for (int i = 0; i < N; ++i) {
        for (int j = !i; j < N; ++j) {
            for (int c = 0; c < 2; ++c) {
                f[i][j][0][c] = (i ? f[i - 1][j][1][c] : false) || (j ? f[i][j - 1][1][!c] : false);
                f[i][j][1][c] = (i ? f[i - 1][j][0][c] : true) && (j ? f[i][j - 1][0][c] : true);
            }
        }
    }
    int T;
    std::cin >> T;
    while (T--) {
        int n, a0 = 0, a1 = 0, x;
        std::cin >> n;
        while (n--) std::cin >> x, ++(x & 1 ? a1 : a0);
        std::cout << (f[a0][a1][0][0] ? "Alice" : "Bob") << '\n';
    }
    return 0;
}