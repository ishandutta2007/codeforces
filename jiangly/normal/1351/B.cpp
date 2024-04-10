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
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a > b)
            std::swap(a, b);
        if (c > d)
            std::swap(c, d);
        if (b == d && a + c == b) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}