#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++i)
            std::cout << "BW"[i == 0] + std::string(m - 1, 'B') << "\n";
    }
    return 0;
}