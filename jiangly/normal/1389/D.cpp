#include <bits/stdc++.h>
int64_t get(int l1, int r1, int l2, int r2, int k, int n) {
    int inter = std::min(r1, r2) - std::max(l1, l2);
    assert(inter >= 0);
    int64_t need = std::max(0ll, k - 1ll * n * inter);
    int len = r1 - l1 + r2 - l2 - 2 * inter;
    if (need <= 1ll * len * n) {
        return need;
    } else {
        return 2 * need - 1ll * len * n;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        int l1, r1;
        std::cin >> l1 >> r1;
        int l2, r2;
        std::cin >> l2 >> r2;
        int64_t ans;
        if (l1 <= r2 && l2 <= r1) {
            ans = get(l1, r1, l2, r2, k, n);
        } else {
            if (l1 > l2) {
                std::swap(l1, l2);
                std::swap(r1, r2);
            }
            int cost = l2 - r1;
            l2 = r1;
            ans = 1e18;
            for (int i = 1; i <= n; ++i)
                ans = std::min(ans, 1ll * i * cost + get(l1, r1, l2, r2, k, i));
        }
        std::cout << ans << "\n";
    }
    return 0;
}