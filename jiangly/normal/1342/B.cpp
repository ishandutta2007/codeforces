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
        std::string s;
        std::cin >> s;
        int n = s.length();
        if (s == std::string(n, '0') || s == std::string(n, '1')) {
            std::cout << s << "\n";
        } else {
            std::string t(2 * n, '0');
            for (int i = 0; i < n; ++i)
                t[2 * i] = '1';
            std::cout << t << "\n";
        }
    }
    return 0;
}