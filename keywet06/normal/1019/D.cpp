#include <bits/stdc++.h>
using int64 = long long;

const int N = 3005;

int n, x[N], y[N];
int64 S, G[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> S;
    S <<= 1;
    for (int i = 1; i <= n; ++i) std::cin >> x[i] >> y[i];
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) G[i][j] = (int64)x[i] * y[j] - (int64)x[j] * y[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int64 aim1 = S - G[i][j], aim2 = -S - G[i][j];
            for (int k = j + 1; k <= n; ++k) {
                int64 t = -G[i][k] + G[j][k];
                if (t == aim1 || t == aim2) {
                    printf("Yes\n%d %d\n%d %d\n%d %d\n", x[i], y[i], x[j], y[j], x[k], y[k]);
                    return 0;
                }
            }
        }
    }
    puts("No");
    return 0;
}