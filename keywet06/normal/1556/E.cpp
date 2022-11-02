#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int64 T, n, q, k, x, y, z;
int64 a[N], ca[N], cb[N], min[N], max[N];

inline void build(int u, int l, int r) {
    if (l == r) return void(min[u] = max[u] = a[l]);
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    min[u] = std::min(min[u << 1], min[u << 1 | 1]);
    max[u] = std::max(max[u << 1], max[u << 1 | 1]);
}

inline int64 querymin(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return min[u];
    int mid = l + r >> 1;
    int64 ret = 1e17;
    if (x <= mid) ret = std::min(ret, querymin(u << 1, l, mid, x, y));
    if (y > mid) ret = std::min(ret, querymin(u << 1 | 1, mid + 1, r, x, y));
    return ret;
}

inline int64 querymax(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return max[u];
    int mid = l + r >> 1;
    int64 ret = -1e17;
    if (x <= mid) ret = std::max(ret, querymax(u << 1, l, mid, x, y));
    if (y > mid) ret = std::max(ret, querymax(u << 1 | 1, mid + 1, r, x, y));
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i) std::cin >> ca[i];
    for (int i = 1; i <= n; ++i) std::cin >> cb[i];
    for (int i = 1; i <= n; ++i) a[i] = ca[i] - cb[i];
    for (int i = 2; i <= n; ++i) a[i] += a[i - 1];
    build(1, 1, n);
    while (q--) {
        std::cin >> x >> y;
        if (querymax(1, 1, n, x, y) > a[x - 1] || a[x - 1] != a[y]) {
            std::cout << -1 << '\n';
            continue;
        }
        std::cout << a[x - 1] - querymin(1, 1, n, x, y) << '\n';
    }
    return 0;
}