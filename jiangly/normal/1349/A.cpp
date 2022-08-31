#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), pre(n), suf(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    pre[0] = 0;
    suf[n - 1] = 0;
    for (int i = 0; i < n - 1; ++i)
        pre[i + 1] = std::gcd(pre[i], a[i]);
    for (int i = n - 1; i > 0; --i)
        suf[i - 1] = std::gcd(suf[i], a[i]);
    long long ans = 1;
    for (int i = 0; i < n; ++i)
        ans = std::lcm(ans, std::gcd(pre[i], suf[i]));
    std::cout << ans << std::endl;
    return 0;
}