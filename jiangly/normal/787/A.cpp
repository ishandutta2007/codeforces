#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    for (int i = std::max(b, d); i <= 20000; ++i) {
        if ((i - b) % a == 0 && (i - d) % c == 0) {
            std::cout << i << "\n";
            return 0;
        }
    }
    std::cout << -1 << "\n";
    
    return 0;
}