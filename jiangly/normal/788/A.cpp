#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = std::abs(a[i] - a[i + 1]);
    }
    int64_t ans = b[n - 2];
    int64_t mx = b[n - 2], mn = b[n - 2];
    for (int i = n - 3; i >= 0; --i) {
        std::tie(mx, mn) = std::make_pair(b[i] + std::max<int64_t>(0, -mn), b[i] + std::min<int64_t>(0, -mx));
        ans = std::max(ans, mx);
    }
    std::cout << ans << "\n";
    
    return 0;
}