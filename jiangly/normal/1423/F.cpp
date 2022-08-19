#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    
    int64_t s1 = 0;
    int s2 = 0;
    for (int i = 0; i < k; ++i) {
        int a, b;
        std::cin >> a >> b;
        s1 += b;
        s2 = (s2 + 1ll * a * b) % n;
    }
    if (s1 > n) {
        std::cout << -1 << "\n";
    } else if (s1 < n) {
        std::cout << 1 << "\n";
    } else if (1ll * n * (n - 1) / 2 % n == s2) {
        std::cout << 1 << "\n";
    } else {
        std::cout << -1 << "\n";
    }
    
    return 0;
}