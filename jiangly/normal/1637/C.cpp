#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    if (std::vector(a.begin() + 1, a.end() - 1) == std::vector(n - 2, 1)) {
        std::cout << "-1\n";
        return;
    }
    
    if (n == 3 && a[1] % 2 == 1) {
        std::cout << "-1\n";
        return;
    }
    
    i64 ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans += a[i] + a[i] % 2;
    }
    std::cout << ans / 2 << "\n";
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