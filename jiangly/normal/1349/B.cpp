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
        int n, k;
        std::cin >> n >> k;
        bool exist = false;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (x < k) {
                a[i] = -1;
            } else if (x > k) {
                a[i] = 1;
            } else {
                a[i] = 1;
                exist = true;
            }
        }
        if (!exist) {
            std::cout << "no\n";
            continue;
        }
        if (n == 1) {
            std::cout << "yes\n";
            continue;
        }
        bool ok = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] + a[i + 1] > 0)
                ok = true;
            if (i < n - 2 && a[i] + a[i + 1] + a[i + 2] > 0)
                ok = true;
        }
        if (ok) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}