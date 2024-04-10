#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        std::vector<bool> b(n);
        for (int i = 0; i < n; ++i)
            b[i] = a[i] != a[(i + 1) % n];
        int s = 0;
        while (s < n && b[s])
            ++s;
        if (s == n) {
            std::cout << 2 + n % 2 << "\n";
            for (int i = 0; i < n; ++i)
                std::cout << (i % 2 == 0 ? i == n - 1 ? 3 : 2 : 1) << " \n"[i == n - 1];
        } else {
            std::vector<int> c(n);
            ++s;
            for (int i = 0, lst = 0; i < n; ++i)
                lst = c[(i + s) % n] = b[(i + s - 1) % n] ? lst ^ 1 : 0;
            std::cout << *std::max_element(c.begin(), c.end()) + 1 << "\n";
            for (int i = 0; i < n; ++i)
                std::cout << c[i] + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}