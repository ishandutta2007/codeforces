#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        if (n % 2 == 0 && n >= 2 * k) {
            std::cout << "YES\n";
            for (int i = 0; i < k; ++i)
                std::cout << (i ? 2 : n - 2 * (k - 1)) << " \n"[i == k - 1];
        } else if (n % 2 == k % 2 && n >= k) {
            std::cout << "YES\n";
            for (int i = 0; i < k; ++i)
                std::cout << (i ? 1 : n - (k - 1)) << " \n"[i == k - 1];
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}