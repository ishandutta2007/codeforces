#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::set<int> s(a.begin(), a.end());
        if (s.size() > k) {
            std::cout << -1 << "\n";
        } else {
            std::cout << k * n << "\n";
            for (int i = 0; i < n; ++i) {
                for (auto j : s)
                    std::cout << j << " ";
                for (int j = s.size(); j < k; ++j)
                    std::cout << 1 << " ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}