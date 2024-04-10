#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << std::max({x + y, 2 * x - 1, 2 * y - 1}) << "\n";
    }
    
    return 0;
}