#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    int x;
    std::cin >> s >> x;
    
    int L, R;
    if (s == "ABC") {
        L = 0;
        R = 1999;
    } else if (s == "ARC") {
        L = 0;
        R = 2799;
    } else {
        L = 1200;
        R = 1E9;
    }
    
    if (L <= x && x <= R) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}