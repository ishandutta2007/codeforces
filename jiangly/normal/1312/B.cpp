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
        std::sort(a.begin(), a.end(), std::greater<>());
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}