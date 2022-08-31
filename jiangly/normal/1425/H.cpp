#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int sgn = (a + b) % 2 == 1 ? -1 : 1;
        std::cout << (sgn == -1 && a + d > 0 ? "Ya" : "Tidak") << " ";
        std::cout << (sgn == -1 && b + c > 0 ? "Ya" : "Tidak") << " ";
        std::cout << (sgn == 1 && b + c > 0 ? "Ya" : "Tidak") << " ";
        std::cout << (sgn == 1 && a + d > 0 ? "Ya" : "Tidak") << "\n";
    }
    
    return 0;
}