#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; ++i)
            std::cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}