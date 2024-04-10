#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    bool bad = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + 1 == a[i + 1]) {
            bad = true;
        }
    }
    
    if (std::count(a.begin(), a.end(), 1) && bad) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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