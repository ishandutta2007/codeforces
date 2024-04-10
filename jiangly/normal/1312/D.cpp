#include <iostream>
#include <vector>
#include <algorithm>
constexpr int P = 998'244'353;
int power(int base, int e) {
    int res = 1;
    while (e > 0) {
        if (e % 2 == 1)
            res = 1LL * res * base % P;
        base = 1LL * base * base % P;
        e /= 2;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    int ans = 1ll * (n - 2) * power(2, n - 3) % P;
    for (int i = 1; i <= n - 1; ++i)
        ans = 1ll * ans * (m - i + 1) % P * power(i, P - 2) % P;
    std::cout << ans << "\n";
    return 0;
}