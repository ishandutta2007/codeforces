#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    i64 h;
    std::cin >> n >> h;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 l = 1, r = h;
    
    while (l < r) {
        i64 x = (l + r) / 2;
        
        i64 res = 0;
        for (int i = 0; i < n - 1; i++) {
            res += std::min(x, a[i + 1] - a[i]);
        }
        res += x;
        
        if (res >= h) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    
    std::cout << l << "\n";
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