#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            for (int k = j; k < n; ++k)
                ans = std::max(ans, a[i] | a[j] | a[k]);
    std::cout << ans << "\n";
    return 0;
}