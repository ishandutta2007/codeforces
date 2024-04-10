#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        int x, y, k;
        std::cin >> x >> y >> k;
        int64_t need = 1ll * k * (y + 1) - 1;
        std::cout << (need + x - 2) / (x - 1) + k << "\n";
    }
    
    return 0;
}