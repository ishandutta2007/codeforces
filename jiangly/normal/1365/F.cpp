#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
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
        if ((n & 1) && a[n / 2] != b[n / 2]) {
            std::cout << "No\n";
            continue;
        }
        std::vector<std::pair<int, int>> pa(n), pb(n);
        for (int i = 0; 2 * i < n; ++i) {
            if (a[i] > a[n - i - 1])
                std::swap(a[i], a[n - i - 1]);
            if (b[i] > b[n - i - 1])
                std::swap(b[i], b[n - i - 1]);
            pa.emplace_back(a[i], a[n - i - 1]);
            pb.emplace_back(b[i], b[n - i - 1]);
        }
        std::sort(pa.begin(), pa.end());
        std::sort(pb.begin(), pb.end());
        if (pa == pb) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}