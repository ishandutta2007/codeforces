#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    if (std::count(a.begin(), a.end(), 0) != 0) {
        std::cout << n - std::count(a.begin(), a.end(), 0) << "\n";
    } else if (std::set(a.begin(), a.end()).size() != a.size()) {
        std::cout << n << "\n";
    } else {
        std::cout << n + 1 << "\n";
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