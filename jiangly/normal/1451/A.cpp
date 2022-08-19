#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n == 1) {
            std::cout << 0 << "\n";
        } else if (n == 2) {
            std::cout << 1 << "\n";
        } else if (n == 3 || n % 2 == 0) {
            std::cout << 2 << "\n";
        } else {
            std::cout << 3 << "\n";
        }
    }
    
    return 0;
}