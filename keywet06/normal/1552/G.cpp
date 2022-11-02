#include <bits/stdc++.h>

using int64 = long long;

const int K = 45;
const int N = 10000005;

int n, k, cnt1, cnt2, c;
int de[K];

int64 vis, q, x, y, z, u, v, w;
int64 f1[N], f2[N];
int64 *f = f1, *g = f2;

inline int pc(int64 x) {
    return __builtin_popcount(x >> 32) + __builtin_popcount(x);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    if (n == 1) return std::cout << "ACCEPTED" << std::endl, 0;
    cnt1 = 1;
    int cnt = 0;
    while (k--) {
        std::cin >> c, cnt2 = q = 0;
        for (int i = 0; i < c; ++i) std::cin >> de[i], q |= 1ll << --de[i];
        for (int _ = 0; u = f[_], _ < cnt1; ++_) {
            x = pc(u & q), y = pc(~vis & q) + 1, z = q, v = ~q & u;
            while (x--) v |= z & -z, z &= z - 1;
            while (y--) g[cnt2++] = v, v |= z & -z, z &= z - 1;
        }
        vis |= q, std::swap(cnt1, cnt2), std::swap(f, g);
    }
    if (pc(vis) < n) return std::cout << "REJECTED" << std::endl, 0;
    for (int _ = 0; u = f[_], _ < cnt1; ++_) {
        if (pc(u >> pc(u))) return std::cout << "REJECTED" << std::endl, 0;
    }
    std::cout << "ACCEPTED" << std::endl, 0;
    return 0;
}