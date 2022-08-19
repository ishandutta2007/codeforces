#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        int na = *std::min_element(a.begin(), a.end());
        int nb = *std::min_element(b.begin(), b.end());
        int64_t ans = 0;
        for (int i = 0; i < n; ++i)
            ans += std::max(a[i] - na, b[i] - nb);
        std::cout << ans << "\n";
    }
    return 0;
}