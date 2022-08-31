#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t a, b, c;
        std::cin >> a >> b >> c;
        std::cout << a + b + c - 1 << "\n";
    }
    
    return 0;
}