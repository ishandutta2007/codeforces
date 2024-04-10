#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y, n;
        std::cin >> x >> y >> n;
        std::cout << (n - y) / x * x + y << "\n";
    }
    return 0;
}