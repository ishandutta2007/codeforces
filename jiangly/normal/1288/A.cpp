#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, d;
        std::cin >> n >> d;
        int x = (n - 1) / 2;
        if (1LL * (n - x) * (x + 1) >= d) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}