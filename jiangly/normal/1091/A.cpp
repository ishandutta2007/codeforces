#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int y, b, r;
    std::cin >> y >> b >> r;
    
    std::cout << std::min({y, b - 1, r - 2}) * 3 + 3 << "\n";
    
    return 0;
}