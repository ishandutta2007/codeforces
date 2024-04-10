#include <bits/stdc++.h>

const int N = 200005;
const int M = 1 << 19;

int n, m;
int a[N], Max[M];

inline void Build(int u, int l, int r) {
    if (l == r) return void(Max[u] = a[l]);
    int Mid = l + r >> 1;
    Build(u << 1, l, Mid), Build(u << 1 | 1, Mid + 1, r);
    Max[u] = std::max(Max[u << 1], Max[u << 1 | 1]);
}

inline int Query(int u, int l, int r, int x, int y) {
    if (l >= x && r <= y) return Max[u];
    int Mid = l + r >> 1, Ans = 0;
    if (x <= Mid) Ans = std::max(Ans, Query(u << 1, l, Mid, x, y));
    if (y > Mid) Ans = std::max(Ans, Query(u << 1 | 1, Mid + 1, r, x, y));
    return Ans;
}

inline int Query(int l, int r) { return l <= r ? Query(1, 1, m, l, r) : 0; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i) std::cin >> a[i];
    Build(1, 1, m);
    int T;
    std::cin >> T;
    while (T--) {
        int lx, ly, rx, ry, k;
        std::cin >> lx >> ly >> rx >> ry >> k;
        if (lx % k != rx % k || ly % k != ry % k) {
            std::cout << "NO" << '\n';
            continue;
        }
        if (ly > ry) std::swap(ly, ry);
        int t = lx + (n - lx) / k * k;
        std::cout << (Query(ly, ry) < t ? "YES" : "NO") << '\n';
    }
    return 0;
}