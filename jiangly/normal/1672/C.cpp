#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int mn = n, mx = -1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            mn = std::min(mn, i);
            mx = std::max(mx, i);
        }
    }
    
    if (mn >= mx) {
        std::cout << "0\n";
    } else {
        std::cout << std::max(1, mx - mn - 1) << "\n";
    }
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