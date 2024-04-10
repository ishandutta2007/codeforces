#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        n /= 2;
        std::cout << 1ll * n * (n + 1) * (2 * n + 1) / 3 * 4 << "\n";
    }
    return 0;
}