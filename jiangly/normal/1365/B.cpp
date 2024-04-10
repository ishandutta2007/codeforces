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
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        std::sort(b.begin(), b.end());
        if (b[0] == b.back() && !std::is_sorted(a.begin(), a.end())) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }
    return 0;
}