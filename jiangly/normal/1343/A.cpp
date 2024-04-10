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
        int s;
        std::cin >> s;
        for (int k = 2; k < 31; ++k) {
            int t = (1 << k) - 1;
            if (s % t == 0) {
                std::cout << s / t << "\n";
                break;
            }
        }
    }
    return 0;
}