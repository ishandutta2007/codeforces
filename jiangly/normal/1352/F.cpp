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
        int n0, n1, n2;
        std::cin >> n0 >> n1 >> n2;
        std::string s;
        if (n0 == 0 || n2 == 0) {
            s = std::string(n0 + n2 + 1, n0 ? '0' : '1');
            while (n1--)
                s += s.back() ^ 1;
        } else {
            s = std::string(n0 + 1, '0') + std::string(n2 + 1, '1');
            while (--n1)
                s += s.back() ^ 1;
        }
        std::cout << s << "\n";
    }
    return 0;
}