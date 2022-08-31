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
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int64_t s = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            s += a[i];
            ans = std::max(ans, -s);
        }
        std::cout << ans << "\n";
    }
    return 0;
}