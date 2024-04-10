#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int t = 0;
    int v = 0;
    
    int l = 1, r = n - 1;
    
    while (l < r) {
        int m = (l + r + 1) / 2;
        int q = (n - m + n - t % n) % n;
        t += q;
        
        std::cout << "+ " << q << std::endl;
        int ans;
        std::cin >> ans;
        
        if (ans == v) {
            r = m - 1;
        } else {
            l = m;
        }
        v = ans;
    }
    
    std::cout << "! " << l + t << std::endl;
    
    return 0;
}