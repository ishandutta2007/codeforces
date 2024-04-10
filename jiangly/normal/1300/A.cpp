#include <iostream>
#include <vector>
#include <numeric>
int t, n;
std::vector<int> a;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int ans = 0, sum = std::accumulate(a.begin(), a.end(), 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                ++ans;
                ++sum;
            }
        }
        std::cout << ans + (sum == 0) << "\n";
    }
    return 0;
}