#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    if (n < 30) {
        m &= (1 << n) - 1;
    }
    
    std::cout << m << "\n";
    
    return 0;
}