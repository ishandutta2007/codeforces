#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }
    
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;
        
        int x = 0;
        for (int i = 0; i < n && x < m; i++) {
            if (b[i] >= x && m - x - 1 <= a[i]) {
                x++;
            }
        }
        
        if (x == m) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    
    std::cout << l << '\n';
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