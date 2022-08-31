#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    
    std::cin >> n >> k;
    
    int x = 1e9;
    
    for (int y = 1; y < k; y++) {
        if (n % y != 0) {
            continue;
        }
        
        x = std::min(x, n / y * k + y);
    }
    
    std::cout << x << "\n";
    
    return 0;
}