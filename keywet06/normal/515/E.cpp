#include <bits/stdc++.h>
using int64 = long long;
const int N = 8000005;
const int64 INF = 1e13;
struct node {
    int64 lr, l_, r_, __;
} a[N];
int64 n, m, lra, l_a, _ra, __a;
int64 h[N], dis[N];
inline int64 ls(int64 p) { return p << 1; }
inline int64 rs(int64 p) { return p << 1 | 1; }
inline void update(int p) {
    a[p].lr =
        std::max(a[ls(p)].l_ + a[rs(p)].r_, std::max(a[ls(p)].lr, a[rs(p)].lr));
    a[p].l_ = std::max(a[ls(p)].l_ + a[rs(p)].__, a[rs(p)].l_);
    a[p].r_ = std::max(a[ls(p)].__ + a[rs(p)].r_, a[ls(p)].r_);
    a[p].__ = a[ls(p)].__ + a[rs(p)].__;
}
inline void build(int64 p, int64 l, int64 r) {
    if (l == r) {
        a[p].l_ = h[l] + dis[l];
        a[p].r_ = h[l] + dis[l];
        a[p].__ = dis[l];
        return;
    }
    int64 mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    update(p);
}
inline void query(int64 p, int64 l, int64 r, int64 L, int64 R) {
    if (L <= l && r <= R) {
        lra = std::max(lra, std::max(a[p].lr, l_a + a[p].r_));
        l_a = std::max(l_a + a[p].__, std::max(a[p].l_, l_a));
        return;
    }
    int64 mid = l + r >> 1;
    if (mid >= L) query(ls(p), l, mid, L, R);
    if (mid < R) query(rs(p), mid + 1, r, L, R);
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin >> n >> m;
    for (int i = 2; i <= 2 * n; i += 2) std::cin >> dis[i], dis[i - 1] = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        std::cin >> h[i], h[i] *= 2;
        h[i + 1] = -INF;
    }
    for (int i = 1; i <= 2 * n; i++) {
        dis[2 * n + i] = dis[i];
        h[i + 2 * n] = h[i];
    }
    build(1, 1, 4 * n - 1);
    for (int i = 1; i <= m; i++) {
        int64 x, y;
        std::cin >> x >> y;
        lra = l_a = -INF;
        if (x == y) {
            query(1, 1, 4 * n - 1, 2 * x + 1, 2 * x - 3 + 2 * n);
        } else if (x < y) {
            query(1, 1, 4 * n - 1, 2 * y + 1, 2 * x - 3 + 2 * n);
        } else {
            query(1, 1, 4 * n - 1, 2 * y + 1, 2 * x - 3);
        }
        std::cout << lra << '\n';
    }
    return 0;
}