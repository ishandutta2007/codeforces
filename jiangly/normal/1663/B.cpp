#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r;
    std::cin >> r;
    
    std::vector v{1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    
    std::cout << *std::upper_bound(v.begin(), v.end(), r) << "\n";
    
    return 0;
}