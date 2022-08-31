#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            int a, b, c, d;
            std::cin >> a >> b >> c >> d;
            if (b == c) ok = true;
        }
        if (ok && m % 2 == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
    
    return 0;
}