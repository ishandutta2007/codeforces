#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int x = 2 * (std::sqrt(n) - 1);
        while ((x / 2 + 1) * (x - x / 2 + 1) < n) ++x;
        std::cout << x << "\n";
    }
    
    return 0;
}