#include <iostream>
#include <tuple>
constexpr int P = 1'000'000'007;
int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans = 1LL * ans * a % P;
        a = 1LL * a * a % P;
        b >>= 1;
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::tie(n, m) = std::make_pair(n + 2 * m - 1, 2 * m);
    int ans = 1;
    for (int i = n; i >= n - m + 1; --i)
        ans = 1LL * ans * i % P;
    for (int i = 1; i <= m; ++i)
        ans = 1LL * ans * power(i, P - 2) % P;
    std::cout << ans << "\n";
    return 0;
}