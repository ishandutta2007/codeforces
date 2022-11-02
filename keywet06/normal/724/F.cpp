#include <bits/stdc++.h>

const int N = 1005;

int n, d, P, f2[N][N][11], ny[N], f[N];

int Quick(int a, int b) {
    int Now = a, ret = 1;
    for (; b; b >>= 1, Now = 1LL * Now * Now % P)
        if (b & 1) ret = 1LL * ret * Now % P;
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> d >> P;
    if (n <= 2) return printf("1"), 0;
    for (int i = 1; i <= 1000; ++i) ny[i] = Quick(i, P - 2);
    f[1] = 1;
    f2[0][0][0] = 1;
    for (int W = 0; W <= d; ++W) f2[1][W][W] = 1;
    for (int i = 2; i * 2 <= n; ++i) {
        f[i] = f2[i - 1][i - 1][d - 1];
        for (int k = 0; k <= d; ++k) {
            for (int j = 0; j <= n; ++j) {
                if (f2[i - 1][j][k]) {
                    int Now = f2[i - 1][j][k];
                    for (int l = 0; j + l * i <= n && l + k <= d && Now; ++l) {
                        f2[i][j + l * i][l + k] += Now;
                        if (f2[i][j + l * i][l + k] >= P) f2[i][j + l * i][l + k] -= P;
                        Now = 1LL * Now * (f[i] + l) % P * ny[l + 1] % P;
                    }
                }
            }
        }
    }
    if (n & 1) {
        printf("%d\n", f2[n >> 1][n - 1][d]);
    } else {
        int ans = f2[(n >> 1) - 1][n - 1][d], Now = f[n >> 1];
        Now = 1LL * (Now + 1) * Now % P * ny[2] % P;
        ans = (ans + Now) % P;
        printf("%d\n", ans);
    }
    return 0;
}