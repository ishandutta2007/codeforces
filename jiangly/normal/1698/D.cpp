#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int L = 1, R = n;
    while (L < R) {
        int m = (L + R) / 2;
        
        std::cout << "? 1 " << m << std::endl;
        
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            std::cin >> x;
            cnt += (x <= m);
        }
        
        if (cnt % 2 == 1) {
            R = m;
        } else {
            L = m + 1;
        }
    }
    
    std::cout << "! " << L << std::endl;
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