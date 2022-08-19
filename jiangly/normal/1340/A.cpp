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
        int n;
        std::cin >> n;
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i];
            --p[i];
        }
        int l = -1, m = n;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (i < n - m && p[i] != p[l] + i - l) {
                ok = false;
                break;
            } else {
                l = i;
                m = p[i];
            }
        }
        if (ok) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}