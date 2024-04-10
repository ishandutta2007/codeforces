#include <bits/stdc++.h>

int main() {
    
    int n;
    std::cin >> n;
    
    std::vector<int> x(n);
    x[0] = 0;
    for (int i = 1; i < n; ++i) {
        std::cout << "XOR 1 " << i + 1 << std::endl;
        std::cin >> x[i];
    }
    
    std::vector<int> vis(n, -1);
    for (int i = 0; i < n; ++i) {
        if (vis[x[i]] != -1) {
            std::cout << "AND " << vis[x[i]] + 1 << " " << i + 1 << std::endl;
            int r;
            std::cin >> r;
            r ^= x[i];
            std::cout << "!";
            for (auto a : x) std::cout << " " << (a ^ r);
            std::cout << std::endl;
            return 0;
        }
        vis[x[i]] = i;
    }
    
    int p = vis[n - 1];
    int q = p == 1 ? 2 : 1;
    
    std::cout << "AND " << q + 1 << " " << p + 1 << std::endl;
    int k;
    std::cin >> k;
    
    int AND;
    std::cout << "AND 1 " << q + 1 << std::endl;
    std::cin >> AND;
    
    int r = 0;
    for (int i = 1; i < n; i *= 2) {
        if (~x[q] & i) {
            r |= AND & i;
        } else {
            r |= ~k & i;
        }
    }
    std::cout << "!";
    for (auto a : x) std::cout << " " << (a ^ r);
    std::cout << std::endl;
    
    return 0;
}