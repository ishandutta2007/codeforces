#include <bits/stdc++.h>

const int N = 1000005;
const int M = 2100000;

int n, m, o, ans;
int l[N], r[N], w[N], p[N];
int plu[M], min[M];

inline void plus(int u, int l, int r, int x, int y, int z) {
    if (l >= x && r <= y) return plu[u] += z, min[u] += z, void(0);
    int mid = l + r >> 1;
    if (x <= mid) plus(u << 1, l, mid, x, y, z);
    if (y > mid) plus(u << 1 | 1, mid + 1, r, x, y, z);
    min[u] = std::min(min[u << 1], min[u << 1 | 1]) + plu[u];
}
inline void plus(int x, int y, int z) { plus(1, 2, m, x, y, z); }

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i] >> w[i], p[i] = i;
    std::sort(p + 1, p + n + 1, [](int x, int y) { return w[x] < w[y]; });
    o = 0, ans = M;
    for (int i = 1; i <= n; ++i) {
        while (!min[1] && o < n) ++o, plus(l[p[o]] + 1, r[p[o]], 1);
        ans = std::min(ans, min[1] ? w[p[o]] - w[p[i]] : M);
        plus(l[p[i]] + 1, r[p[i]], -1);
    }
    std::cout << ans << std::endl;
    return 0;
}