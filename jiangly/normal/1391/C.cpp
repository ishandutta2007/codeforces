#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ++i)
        ans = 1ll * ans * i % P;
    int res = 1;
    for (int i = 0; i < n - 1; ++i)
        res = 2ll * res % P;
    std::cout << (ans - res + P) % P << "\n";
    return 0;
}