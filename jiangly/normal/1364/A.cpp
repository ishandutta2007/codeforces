#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int u = -1, v = -1;
        int ans = -1, sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + a[i]) % x;
            if (sum)
                ans = std::max(ans, i + 1);
            if (u != -1 && sum != u)
                ans = std::max(ans, i + 1 - v);
            if (u == -1 && sum) {
                u = sum;
                v = i + 1;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}