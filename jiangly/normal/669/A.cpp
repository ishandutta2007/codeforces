#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::cout << (n / 3 * 2 + (n % 3 > 0)) << "\n";
    
    return 0;
}