#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << ((n - k) % 2 == 0 && n >= 1ll * k * k ? "YES" : "NO") << "\n";
    }
    return 0;
}