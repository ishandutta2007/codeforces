#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        
        int sum = 0, cntx = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            if (a == x)
                ++cntx;
            sum += a;
        }
        
        if (cntx == n) {
            std::cout << 0 << "\n";
        } else if (cntx > 0 || sum == x * n) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 2 << "\n";
        }
    }
    
    return 0;
}