#include <bits/stdc++.h>

using int64 = long long;

namespace oct {

void sync();

inline void ios() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
}

}  // namespace oct

const int C = 20;
const int N = 150010;
const int P = 1e9 + 7;
const int V = (P + 1) / 2;

int n, m;
int f[N], a[N], b[N], c[N], cnt[N];
int d[C][N], e[C][N];

inline void FWT_or(int *a, int n, int f) {
    for (int l = 1; l < n; l <<= 1) {
        for (int i = 0; i < n; i += (l << 1)) {
            for (int j = 0; j < l; ++j) {
                a[i + l + j] = ((a[i + l + j] + f * a[i + j]) % P + P) % P;
            }
        }
    }
}
inline void FWT_and(int *a, int n, int f) {
    for (int l = 1; l < n; l <<= 1) {
        for (int i = 0; i < n; i += (l << 1)) {
            for (int j = 0; j < l; ++j) {
                a[i + j] = ((a[i + j] + f * a[i + l + j]) % P + P) % P;
            }
        }
    }
}
inline void FWT_xor(int *a, int n, int f) {
    for (int l = 1; l < n; l <<= 1) {
        for (int i = 0; i < n; i += (l << 1)) {
            for (int j = 0; j < l; ++j) {
                int t = a[i + l + j];
                a[i + l + j] = (a[i + j] - t + P) % P;
                a[i + j] = (a[i + j] + t) % P;
                if (f == -1) {
                    a[i + l + j] = 1ll * a[i + l + j] * V % P;
                    a[i + j] = 1ll * a[i + j] * V % P;
                }
            }
        }
    }
}

int main() {
    oct::ios();
    std::cin >> n;
    for (int i = 1, x; i <= n; ++i) std::cin >> x, ++a[x];
    n = 17, m = 1 << 17, cnt[1] = f[1] = 1;
    for (int i = 2; i < m; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % P, cnt[i] = cnt[i - (i & (-i))] + 1;
    }
    memcpy(c, a, m * sizeof(int));
    for (int i = 0; i < m; ++i) d[cnt[i]][i] = a[i];
    for (int i = 0; i <= n; ++i) FWT_or(d[i], m, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int s = 0; s < m; ++s) {
                e[i][s] = (e[i][s] + 1ll * d[j][s] * d[i - j][s] % P) % P;
            }
        }
    }
    for (int i = 0; i <= n; ++i) FWT_or(e[i], m, -1);
    for (int i = 0; i < m; ++i) b[i] = 1ll * e[cnt[i]][i] * f[i] % P;
    FWT_xor(c, m, 1);
    for (int i = 0; i < m; ++i) c[i] = 1ll * c[i] * c[i] % P;
    FWT_xor(c, m, -1);
    for (int i = 0; i < m; ++i) c[i] = 1ll * c[i] * f[i] % P;
    for (int i = 0; i < m; ++i) a[i] = 1ll * a[i] * f[i] % P;
    FWT_and(a, m, 1), FWT_and(b, m, 1), FWT_and(c, m, 1);
    for (int i = 0; i < m; ++i) a[i] = 1ll * a[i] * b[i] % P * c[i] % P;
    FWT_and(a, m, -1);
    int ans = 0;
    for (int i = 1; i < m; i <<= 1) ans = (ans + a[i]) % P;
    std::cout << ans << std::endl;
    return 0;
}