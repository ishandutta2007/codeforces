#include <bits/stdc++.h>
constexpr int P = 998244353;
int power(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1)
            res = 1ll * res * a % P;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    n /= 2;
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());
    for (int i = k - 1; i >= 0; --i)
        a[i] -= a[0];
    std::vector<int> f(a.back() * n + 1);
    f[0] = 1;
    for (int i = 0; i < a.back() * n; ++i) {
        int res = 0;
        for (auto j : a)
            if (j && j <= i + 1)
                res = (res + 1ll * j * f[i - j + 1]) % P;
        res = 1ll * res * n % P;
        for (auto j : a)
            if (j && j <= i)
                res = (res + 1ll * (i - j + 1) * (P - f[i - j + 1])) % P;
        f[i + 1] = 1ll * res * power(i + 1, P - 2) % P;
    }
    int ans = 0;
    for (int i = 0; i <= a.back() * n; ++i)
        ans = (ans + 1ll * f[i] * f[i]) % P;
    std::cout << ans << "\n";
    return 0;
}