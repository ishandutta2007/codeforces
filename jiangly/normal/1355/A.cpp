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
        long long a, k;
        std::cin >> a >> k;
        --k;
        while (k > 0) {
            --k;
            auto s = std::to_string(a);
            auto [min, max] = std::minmax_element(s.begin(), s.end());
            if (*min == '0')
                break;
            a += (*min - '0') * (*max - '0');
        }
        std::cout << a << "\n";
    }
    return 0;
}