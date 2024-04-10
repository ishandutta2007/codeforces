#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << (a < c ? 1 : -1) << " " << (1ll * a * b > c ? b : -1) << "\n"; 
    }
    return 0;
}