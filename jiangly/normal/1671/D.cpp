#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += std::abs(a[i] - a[i + 1]);
    }
    
    int min = *std::min_element(a.begin(), a.end());
    int max = *std::max_element(a.begin(), a.end());
    
    if (min > 1 && max < x) {
        ans += std::min({ 2 * (min - 1) + std::min({ 2 * (x - max), x - a[0], x - a[n - 1] }),
                        2 * (x - max) + std::min(a[0] - 1, a[n - 1] - 1), 
                        a[0] - 1 + x - a[n - 1],
                        a[n - 1] - 1 + x - a[0] });
    } else if (min > 1) {
        ans += std::min({ 2 * (min - 1), a[0] - 1, a[n - 1] - 1 });
    } else if (max < x) {
        ans += std::min({ 2 * (x - max), x - a[0], x - a[n - 1] });
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}