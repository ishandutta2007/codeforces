#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    if (m == 1) {
        std::cout << n - 1 << "\n";
    } else {
        std::cout << 1LL * n * (m - 1) << "\n";
    }
    
    return 0;
}