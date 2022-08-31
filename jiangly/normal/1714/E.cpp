#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        
        for (int j = 0; j < 10; j++) {
            a[i] += a[i] % 10;
        }
        while (a[i] % 10 != 2 && a[i] % 10 != 0) {
            a[i] += a[i] % 10;
        }
        if (a[i] % 10 == 2) {
            a[i] %= 20;
        }
    }
    
    if (a == std::vector(n, a[0])) {
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