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
        std::cout << n - std::count(s.begin(), s.end(), '0') << "\n";
        for (int i = 0; i < n; ++i)
            if (s[i] != '0')
                std::cout << s[i] + std::string(n - i - 1, '0') << " ";
        std::cout << "\n";
    }
    return 0;
}