#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::cout << 3 * n + 4 << "\n";
    std::cout << 0 << " " << 0 << "\n";
    for (int i = 0; i <= n; ++i) {
        std::cout << i << " " << i + 1 << "\n";
        std::cout << i + 1 << " " << i << "\n";
        std::cout << i + 1 << " " << i + 1 << "\n";
    }
    return 0;
}