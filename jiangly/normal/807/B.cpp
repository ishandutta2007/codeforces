#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int p, x, y;
    std::cin >> p >> x >> y;
    
    auto check = [&](int s) {
        int i = s / 50 % 475;
        for (int _ = 0; _ < 25; _++) {
            i = (i * 96 + 42) % 475;
            if (26 + i == p) {
                return true;
            }
        }
        return false;
    };
    
    for (int i = x; i >= y; i -= 50) {
        if (check(i)) {
            std::cout << "0\n";
            return 0;
        }
    }
    
    for (int i = 1; ; i++) {
        if (check(x + i * 100) || check(x + i * 100 - 50)) {
            std::cout << i << "\n";
            break;
        }
    }
    
    return 0;
}