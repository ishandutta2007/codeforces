#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, q;
        std::cin >> n >> q;
        std::vector<int> a(n + 2);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        int64_t ans = 0;
        auto add = [&](int x, int c) {
            if (x == 0 || x == n + 1)
                return;
            if (a[x] > a[x - 1] && a[x] > a[x + 1])
                ans += a[x] * c;
            if (a[x] < a[x - 1] && a[x] < a[x + 1])
                ans -= a[x] * c;
        };
        for (int i = 1; i <= n; ++i)
            add(i, 1);
        std::cout << ans << "\n";
        while (q--) {
            int l, r;
            std::cin >> l >> r;
            for (int i = -1; i <= 1; ++i) {
                add(l + i, -1);
                if (r + i > l + 1)
                    add(r + i, -1);
            }
            std::swap(a[l], a[r]);
            for (int i = -1; i <= 1; ++i) {
                add(l + i, 1);
                if (r + i > l + 1)
                    add(r + i, 1);
            }
            std::cout << ans << "\n";
        }
    }
    
    return 0;
}