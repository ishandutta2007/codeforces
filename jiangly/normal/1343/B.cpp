#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
constexpr int INF = 1e8;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n % 4 != 0) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
            for (int i = 1; i <= n / 4; ++i)
                std::cout << INF - 2 * i << " ";
            for (int i = 1; i <= n / 4; ++i)
                std::cout << INF + 2 * i << " ";
            for (int i = 1; i <= n / 4; ++i)
                std::cout << INF - 2 * i + 1 << " ";
            for (int i = 1; i <= n / 4; ++i)
                std::cout << INF + 2 * i - 1 << " \n"[i == n / 4];
        }
    }
    return 0;
}