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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> fac(n + m + 2), invFac(n + m + 2);
    fac[0] = 1;
    for (int i = 1; i <= n + m + 1; ++i)
        fac[i] = 1ll * fac[i - 1] * i % P;
    invFac[n + m + 1] = power(fac[n + m + 1], P - 2);
    for (int i = n + m + 1; i; --i)
        invFac[i - 1] = 1ll * invFac[i] * i % P;
    int s1 = fac[m - 1], s2 = 0, s3 = 0, dp = 0;
    for (int s = 1; s <= n; ++s) {
        s1 = (s1 + 1ll * fac[m - 1 + s] * invFac[s]) % P;
        s2 = (s2 + 1ll * fac[m - 1 + s] * (P - invFac[s - 1])) % P;
        int x = 1ll * m * fac[s] % P;
        dp = (1ll * (s + 1) * s1 + s2) % P * (n + m + 1) % P * invFac[m + s + 1] % P;
        dp = (dp + 1ll * s3 * invFac[m + s]) % P;
        dp = 1ll * dp * x % P * (m + s) % P * invFac[s] % P * fac[s - 1] % P;
        s3 = (s3 + 1ll * dp * fac[m - 1 + s] % P * invFac[s]) % P;
    }
    std::cout << dp << "\n";
    return 0;
}