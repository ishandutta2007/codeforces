#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
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
        std::sort(a.begin(), a.end());
        long long sum = 0, y = n;
        while (y > 0 && 1ll * x * (n - y + 1) <= a[y - 1] + sum)
            sum += a[--y];
        std::cout << n - y << "\n";
    }
    return 0;
}