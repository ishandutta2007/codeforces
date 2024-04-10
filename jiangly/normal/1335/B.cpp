#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        for (int i = 0; i < n; ++i)
            std::cout << char(i % a < b - 1 ? 'a' + i % a : 'z');
        std::cout << "\n";
    }
    return 0;
}