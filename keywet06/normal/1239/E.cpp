#include <bits/stdc++.h>

const int N = 25;
const int M = N * 50000;

int n, s, h;
int a[N << 1], Vis[N << 1], f[N][M], r[N][M];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 0; i < n << 1; ++i) std::cin >> a[i], s += a[i];
    std::sort(a, a + n + n), s -= a[0] + a[1], h = s / 2;
    f[0][0] = 1;
    for (int i = 2, s = 0; i < n + n; ++i) {
        s = std::min(s + a[i], h);
        for (int j = n - 1; j; --j) {
            for (int k = a[i]; k <= s; ++k) {
                if (!f[j][k] && f[j - 1][k - a[i]]) f[j][k] = 1, r[j][k] = i;
            }
        }
    }
    int e = h, g = n - 1;
    while (!f[g][e]) --e;
    while (g) Vis[r[g][e]] = 1, e -= a[r[g--][e]];
    std::cout << a[0];
    for (int i = 2; i < n + n; ++i) {
        if (Vis[i]) std::cout << ' ' << a[i];
    }
    std::cout << '\n';
    for (int i = n + n - 1; i > 1; --i) {
        if (!Vis[i]) std::cout << a[i] << ' ';
    }
    std::cout << a[1] << '\n';
    return 0;
}