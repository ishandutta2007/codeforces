#include <bits/stdc++.h>
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = int64_t(a) * a % P)
        if (b % 2) res = int64_t(res) * a % P;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; ++i)
        ans = (ans + int64_t(std::min(i + 1, 2 * n - i - 1)) * (a[i + 1] - a[i])) % P;
    int fac = 1;
    for (int i = 1; i <= n; ++i) {
        ans = int64_t(ans) * (n + i) % P;
        fac = int64_t(fac) * i % P;
    }
    ans = int64_t(ans) * power(fac, P - 2) % P;
    std::cout << ans << "\n";
    
    return 0;
}