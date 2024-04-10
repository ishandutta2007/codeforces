#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        s ^= a;
    }
    if (n % 2 == 0) {
        if (s != 0) {
            std::cout << "NO\n";
            return 0;
        }
        --n;
    }
    std::cout << "YES\n";
    std::cout << n - 2 << "\n";
    for (int i = 3; i <= n; i += 2) std::cout << i - 2 << " " << i - 1 << " " << i << "\n";
    for (int i = n - 4; i >= 1; i -= 2) std::cout << i << " " << i + 1 << " " << i + 2 << "\n";
    
    return 0;
}