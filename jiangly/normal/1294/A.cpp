#include <iostream>
int t, a, b, c, n;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c >> n;
        if ((a + b + c + n) % 3 == 0 && n >= 3 * std::max(a, std::max(b, c)) - a - b - c) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}