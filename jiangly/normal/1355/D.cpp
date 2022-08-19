#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, s;
    std::cin >> n >> s;
    if (s < 2 * n) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (int i = 0; i < n; ++i)
            std::cout << (i < n - 1 ? 1 : s - n + 1) << " \n"[i == n - 1];
        std::cout << n << "\n";
    }
    return 0;
}