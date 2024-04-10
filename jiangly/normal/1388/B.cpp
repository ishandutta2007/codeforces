#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int x = (n + 3) / 4;
        std::cout << std::string(n - x, '9') + std::string(x, '8') << "\n";
    }
    return 0;
}