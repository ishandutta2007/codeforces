#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int64_t k;
        std::cin >> k;
        if (k % 2 == 1) {
            std::cout << -1 << "\n";
            continue;
        }
        int n = 0;
        std::vector<int> a;
        for (int i = 60; i >= 1; --i) {
            int64_t x = (2ll << i) - 2;
            while (k >= x) {
                k -= x;
                a.push_back(1);
                a.insert(a.end(), i - 1, 0);
                n += i;
            }
        }
        std::cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}