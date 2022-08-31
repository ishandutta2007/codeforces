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
        std::vector<int> e(n);
        for (int i = 0; i < n; ++i)
            std::cin >> e[i];
        std::sort(e.begin(), e.end());
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (i - j + 1 >= e[i]) {
                ++ans;
                j = i + 1;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}