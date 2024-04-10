#include <bits/stdc++.h>

const int N = 500;
const int M = 100005;

int T, n, m, k, sa, sb, pa, pb, pc, f;
int a[M], p[M], da[M], db[M], dc[M];
int map[N][N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> m >> k, n = 1, pa = pb = pc = 0;
        for (int i = 1; i <= k; ++i) std::cin >> a[p[i] = i];
        std::sort(p + 1, p + k + 1, [](int x, int y) { return a[x] > a[y]; });
        while ((n + 1) / 2 * n < a[p[1]] || n * n - (n / 2) * (n / 2) < m) ++n;
        sa = ((n + 1) / 2) * ((n + 1) / 2), sb = (n / 2) * ((n + 1) / 2);
        for (int i = 1; i <= k; ++i, f = 1) {
            while (pb < sb && a[p[i]]) --a[p[i]], db[++pb] = p[i], f = 0;
            while (pc < sb && a[p[i]] && f) --a[p[i]], dc[++pc] = p[i];
            while (pa < sa && a[p[i]]) --a[p[i]], da[++pa] = p[i];
        }
        for (int i = 1; i <= n; ++++i) {
            for (int j = 1; j <= n; ++++j) map[i][j] = pa ? da[pa--] : 0;
        }
        for (int i = 2; i <= n; ++++i) {
            for (int j = 1; j <= n; ++++j) map[i][j] = pb ? db[pb--] : 0;
        }
        for (int i = 1; i <= n; ++++i) {
            for (int j = 2; j <= n; ++++j) map[i][j] = pc ? dc[pc--] : 0;
        }
        std::cout << n << '\n';
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) std::cout << map[i][j] << ' ';
            std::cout << '\n';
        }
    }
    return 0;
}