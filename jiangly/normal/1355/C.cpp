#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long ans = 0;
    for (int x = a; x <= b; ++x) {
        int l1 = x + b, r1 = x + c;
        int l2 = c + 1, r2 = d + 1;
        l1 = std::max(l1, l2);
        r2 = std::min(r2, r1);
        if (l1 > r1 || l2 > r2)
            continue;
        if (l1 >= r2) {
            ans += 1ll * (r1 - l1 + 1) * (r2 - l2 + 1);
        } else {
            ans += 1ll * (l1 - l2 + 1 + r2 - l2) * (r2 - l1) / 2 + 1ll * (r1 - r2 + 1) * (r2 - l2 + 1);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}