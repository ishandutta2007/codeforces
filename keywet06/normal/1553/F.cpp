#include <bits/stdc++.h>

using int64 = long long;

const int V = 300000;
const int N = V + 5;
const int M = N << 2;

int n;

int64 sum, ans, x;
int64 s[M], t[M];

inline void updates(int u, int l, int r, int x, int y, int z) {
    if (l >= x && r <= y) return void(s[u] += z);
    int mid = l + r >> 1;
    if (x <= mid) updates(u << 1, l, mid, x, y, z);
    if (y > mid) updates(u << 1 | 1, mid + 1, r, x, y, z);
}

inline int64 querys(int u, int l, int r, int x) {
    if (l == r) return s[u];
    int mid = l + r >> 1;
    return s[u] + (x <= mid ? querys(u << 1, l, mid, x)
                            : querys(u << 1 | 1, mid + 1, r, x));
}

inline void updatet(int u, int l, int r, int x, int y) {
    if (l == r) return void(t[u] += y);
    int mid = l + r >> 1;
    if (x <= mid) updatet(u << 1, l, mid, x, y);
    if (x > mid) updatet(u << 1 | 1, mid + 1, r, x, y);
    t[u] += y;
}

inline int64 queryt(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return t[u];
    int mid = l + r >> 1;
    int64 ans = 0;
    if (x <= mid) ans += queryt(u << 1, l, mid, x, y);
    if (y > mid) ans += queryt(u << 1 | 1, mid + 1, r, x, y);
    return ans;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x;
        ans += (i - 1) * x + sum, sum += x;
        ans -= querys(1, 1, V, x);
        for (int j = x; j <= V; j += x) ans -= x * queryt(1, 1, V, j, V);
        for (int j = x; j <= V; j += x) updates(1, 1, V, j, V, x);
        updatet(1, 1, V, x, 1);
        std::cout << ans << ' ';
    }
    std::cout << std::endl;
    return 0;
}