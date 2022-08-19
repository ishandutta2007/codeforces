#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
        }
        std::vector<int> c1(n), c2(n);
        for (int i = 0; i < n; ++i) {
            std::fill(c1.begin(), c1.end(), 0);
            std::fill(c2.begin(), c2.end(), 0);
            for (int l = i + 1; l < n; ++l)
                ++c2[a[l]];
            int64_t res = 0;
            for (int k = i + 1; k < n; ++k) {
                res -= c1[a[k]];
                --c2[a[k]];
                if (a[i] == a[k])
                    ans += res;
                res += c2[a[k]];
                ++c1[a[k]];
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}