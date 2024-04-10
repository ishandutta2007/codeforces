#include <bits/stdc++.h>

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int N = 100005;

int T, n, ar, br, al, bl;
int a[N], b[N], pa[N], pb[N], qa[N], qb[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i], pa[i] = i;
        for (int i = 1; i <= n; ++i) std::cin >> b[i], pb[i] = i;
        std::sort(pa + 1, pa + n + 1, [](int x, int y) { return a[x] < a[y]; });
        std::sort(pb + 1, pb + n + 1, [](int x, int y) { return b[x] < b[y]; });
        for (int i = 1; i <= n; ++i) qa[pa[i]] = i;
        for (int i = 1; i <= n; ++i) qb[pb[i]] = i;
        al = bl = n, ar = n + 1, br = n + 1;
        while (al < ar) {
            while (al < ar) bl = std::min(bl, qb[pa[--ar]]);
            while (bl < br) al = std::min(al, qa[pb[--br]]);
        }
        for (int i = 1; i <= n; ++i) std::cout << (qa[i] >= al || qb[i] >= bl);
        std::cout << '\n';
    }
    return 0;
}