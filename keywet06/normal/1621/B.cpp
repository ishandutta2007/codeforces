#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        int l, r, c, ll, rr, lc, rc, tl, tr, tc, g;
        std::cin >> l >> r >> c;
        tl = ll = l, tr = rr = r, tc = lc = rc = c;
        std::cout << c << '\n';
        for (int i = 1; i < n; ++i) {
            std::cin >> l >> r >> c;
            if (l < ll || l == ll && c < lc) ll = l, lc = c;
            if (r > rr || r == rr && c < rc) rr = r, rc = c;
            if (l == ll && r == rr) {
                tc = tl == ll && tr == rr && tc < c ? tc : c;
                tl = l, tr = r;
            }
            g = tl == ll && tr == rr;
            std::cout << (g ? std::min(tc, lc + rc) : lc + rc) << '\n';
        }
    }
    return 0;
}