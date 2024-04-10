#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        if (2 * l >= r + 1) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    
    return 0;
}