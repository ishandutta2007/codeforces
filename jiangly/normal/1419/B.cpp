#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t x;
        std::cin >> x;
        
        int64_t a = 1;
        int ans = 0;
        while (a * (a + 1) / 2 <= x) {
            x -= a * (a + 1) / 2;
            ++ans;
            a = 2 * a + 1;
        }
        
        std::cout << ans << "\n";
    }
    
    return 0;
}