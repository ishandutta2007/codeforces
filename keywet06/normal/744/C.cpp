#include <bits/stdc++.h>
const int N = 16;
const int N1 = N + 1;
const int T = 126;
const int Z = 1 << N;
int n, suma, sumb;
int a[N], b[N];
int ca[Z], cb[Z];
int f[Z][T];
char ch[N];
int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> ch >> a[i] >> b[i];
        suma += a[i], sumb += b[i];
        for (int j = 0; j < 1 << n; ++j) {
            if (j >> i & 1) ++(*ch == 'R' ? ca[j] : cb[j]);
        }
    }
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int S = 0; S < 1 << n; ++S) {
        for (int j = 0; j < T; ++j) {
            if (!~f[S][j]) continue;
            for (int i = 0; i < n; ++i) {
                if (S >> i & 1) continue;
                int T = S | (1 << i);
                int ta = std::min(a[i], ca[S]), tb = std::min(b[i], cb[S]);
                f[T][j + ta] = std::max(f[T][j + ta], f[S][j] + tb);
            }
        }
    }
    int ans = 1061109567;
    for (int i = 0; i < T; ++i) {
        if (~f[(1 << n) - 1][i]) {
            ans = std::min(ans, std::max(suma - i, sumb - f[(1 << n) - 1][i]));
        }
    }
    std::cout << ans + n << std::endl;
    return 0;
}