#include <bits/stdc++.h>

using int64 = long long;

const int M = 998244353;
const int N = 100005;

int64 x, y, K, n, m, opt, d, dd;
int64 a[N], b[N], c[N];

inline int64 Pow(int64 x, int64 y) {
    if (!y) return 1;
    int64 z = Pow(x, y / 2);
    z *= z, z %= M;
    if (y & 1) z *= x;
    return z % M;
}

inline void Init(std::vector<int64>& y, int64 len) {
    for (int64 i = 1, j = len / 2; i < len - 1; ++i) {
        if (i < j) std::swap(y[i], y[j]);
        int64 k = len / 2;
        while (j >= k) j -= k, k /= 2;
        j += k;
    }
}

inline void NTT(std::vector<int64>& y, int64 len, int64 opt) {
    Init(y, len);
    for (int64 h = 2; h <= len; h <<= 1) {
        int64 wn = Pow(3, (M - 1) / h);
        if (opt == -1) wn = Pow(wn, M - 2);
        for (int64 j = 0; j < len; j += h) {
            int64 w = 1;
            for (int64 k = j; k < j + h / 2; ++k) {
                int64 u = y[k], v = w * y[k + h / 2] % M;
                y[k] = (u + v) % M, y[k + h / 2] = (u + M - v) % M, w = w * wn % M;
            }
        }
    }
    if (opt == 1) return;
    int64 temp = Pow(len, M - 2);
    for (int64 i = 0; i < len; ++i) (y[i] *= temp) %= M;
}

inline void Solve(int64 l, int64 r, std::vector<int64>& f) {
    if (l == r) return f.resize(2), f[0] = 1, f[1] = a[l], void(0);
    int64 len = 1;
    while (len < r - l + 2) len *= 2;
    std::vector<int64> Lef, Rig;
    int64 Mid = (l + r) / 2;
    f.resize(len), Solve(l, Mid, Lef), Solve(Mid + 1, r, Rig);
    Lef.resize(len), Rig.resize(len), NTT(Lef, len, 1), NTT(Rig, len, 1);
    for (int64 i = 0; i < len; ++i) f[i] = Lef[i] * Rig[i] % M;
    NTT(f, len, -1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> K;
    for (int64 i = 1; i <= n; ++i) std::cin >> b[i], c[i] = b[i];
    std::cin >> m;
    while (m--) {
        std::cin >> opt >> dd;
        if (opt == 1) {
            std::cin >> x >> y;
            b[x] = y;
        } else {
            std::cin >> x >> y >> d;
            for (int64 i = x; i <= y; ++i) (b[i] += d) %= M;
        }
        for (int64 i = 1; i <= n; ++i) a[i] = (dd - b[i] + M) % M;
        std::vector<int64> f;
        Solve(1, n, f);
        std::cout << f[K] << '\n';
        for (int64 i = 1; i <= n; ++i) b[i] = c[i];
    }
    return 0;
}