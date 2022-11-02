#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;
const int M = 1 << 20;

int n, kp, k, ans = M;
int l[N];

int64 size[M], plus[M];

inline void pushdown(int u, const int l, const int r, const int mid) {
    if (!plus[u]) return;
    plus[u << 1] += plus[u], size[u << 1] += plus[u] * (mid - l + 1);
    plus[u << 1 | 1] += plus[u], size[u << 1 | 1] += plus[u] * (r - mid);
    plus[u] = 0;
}

inline void update(const int u, const int l, const int r, const int x,
                   const int y, const int v) {
    if (l >= x && r <= y) return plus[u] += v, void(size[u] += v * (r - l + 1));
    int mid = l + r >> 1;
    if (x <= mid) update(u << 1, l, mid, x, y, v);
    if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, v);
    size[u] = size[u << 1] + size[u << 1 | 1] + plus[u] * (r - l + 1);
}

inline int query(const int u, const int l, const int r, const int k) {
    if (l == r) return l;
    int mid = l + r >> 1;
    pushdown(u, l, r, mid);
    return k <= size[u << 1] ? query(u << 1, l, mid, k)
                             : query(u << 1 | 1, mid + 1, r, k - size[u << 1]);
}

inline void add(int x) {
    int d = query(1, 0, kp, 1);
    update(1, 0, kp, d, d, -1), ++d, --x;
    update(1, 0, kp, d + 1, d + (x >> 1), 1);
    update(1, 0, kp, d + 1, d + (x >> 1) + (x & 1), 1);
}

inline void query() {
    ans = std::min(ans, size[1] < k ? M : query(1, 0, kp, k));
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k, kp = N << 1;
    for (int i = 1; i <= n; ++i) std::cin >> l[i];
    std::sort(l + 1, l + n + 1, [](int x, int y) { return x > y; });
    update(1, 0, kp, 0, 0, 1);
    for (int i = 1; i <= n; ++i) add(l[i]), query();
    std::cout << (ans == M ? -1 : ans) << std::endl;
    return 0;
}