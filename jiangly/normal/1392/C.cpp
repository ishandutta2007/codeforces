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
        int64_t ans = 0;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1])
                ans += a[i] - a[i + 1];
        std::cout << ans << "\n";
    }
    return 0;
}