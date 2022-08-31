#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int ang;
        std::cin >> ang;
        
        int n = 3;
        while (ang * n % 180 != 0 || n * ang > (n - 2) * 180) {
            n++;
        }
        
        std::cout << n << "\n";
    }
    
    return 0;
}