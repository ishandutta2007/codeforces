#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    p[n - 1] = 1;
    
    for (int i = 2; i <= n; i++) {
        std::cout << "?";
        for (int j = 2; j <= n; j++) {
            std::cout << " " << i;
        }
        std::cout << " 1\n";
        std::cout << std::endl;
        int x;
        std::cin >> x;
        if (x != 0) {
            p[x - 1] = 1 - i;
            p[n - 1]++;
        }
    }
    for (int i = 2; i <= n; i++) {
        std::cout << "?";
        for (int j = 2; j <= n; j++) {
            std::cout << " 1";
        }
        std::cout << " " << i;
        std::cout << std::endl;
        int x;
        std::cin >> x;
        if (x != 0) {
            p[x - 1] = i - 1;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        p[i] += p[n - 1];
    }
    
    std::cout << "!";
    for (auto x : p) {
        std::cout << " " << x;
    }
    std::cout << std::endl;
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}