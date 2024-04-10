#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 x1, p1, x2, p2;
    std::cin >> x1 >> p1;
    std::cin >> x2 >> p2;
    
    i64 t = std::min(p1, p2);
    p1 -= t;
    p2 -= t;
    
    if (p1 > 10) {
        std::cout << ">\n";
    } else if (p2 > 10) {
        std::cout << "<\n";
    } else {
        while (p1--) {
            x1 *= 10;
        }
        while (p2--) {
            x2 *= 10;
        }
        if (x1 < x2) {
            std::cout << "<\n";
        } else if (x1 == x2) {
            std::cout << "=\n";
        } else {
            std::cout << ">\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}