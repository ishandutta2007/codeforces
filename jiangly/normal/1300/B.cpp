#include <iostream>
#include <vector>
#include <algorithm>
int t, n;
std::vector<int> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.resize(2 * n);
        for (int i = 0; i < 2 * n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        std::cout << a[n] - a[n - 1] << "\n";
    }
    return 0;
}