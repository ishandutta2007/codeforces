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
        int n;
        std::cin >> n;
        int lp = 0, lc = 0;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int p, c;
            std::cin >> p >> c;
            if (p < lp || c < lc || c - lc > p - lp)
                ok = false;
            lp = p;
            lc = c;
        }
        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}