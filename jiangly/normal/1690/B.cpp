#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    int l = 0, r = 1E9;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            l = std::max(l, a[i]);
        } else {
            l = std::max(l, a[i] - b[i]);
            r = std::min(r, a[i] - b[i]);
        }
    }
    
    if (l <= r) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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