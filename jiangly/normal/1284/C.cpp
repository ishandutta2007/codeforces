#include <iostream>
#include <vector>
int n, m;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    std::vector<int> factorial(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = 1LL * factorial[i - 1] * i % m;
    int ans = 0;
    for (int len = 1; len <= n; ++len)
        ans = (ans + 1LL * (n - len + 1) * (n - len + 1) % m * factorial[len] % m * factorial[n - len]) % m;
    std::cout << ans << "\n";
    return 0;
}