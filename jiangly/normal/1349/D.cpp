// luogu
#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
constexpr int P = 998244353;
int power(int base, int e) {
    int res = 1;
    while (e > 0) {
        if (e % 2 == 1)
            res = 1ll * res * base % P;
        base = 1ll * base * base % P;
        e /= 2;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int s = std::accumulate(a.begin(), a.end(), 0);
    std::vector<int> fac(s);
    fac[0] = 1;
    for (int i = 1; i < s; ++i)
        fac[i] = 1ll * fac[i - 1] * i % P;
    int invFac = power(fac[s - 1], P - 2);
    std::vector<int> inv(s);
    for (int i = s - 1; i > 0; --i) {
        inv[i] = 1ll * invFac * fac[i - 1] % P;
        invFac = 1ll * invFac * i % P;
    }
    std::vector<int> f(s + 1);
    f[0] = n - 1;
    for (int i = 1; i < s; ++i)
        f[i] = 1ll * (n - 1) * (s + 1ll * i * f[i - 1] % P) % P * inv[s - i] % P;
    for (int i = s - 1; i >= 0; --i)
        f[i] = (f[i] + f[i + 1]) % P;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = (ans + f[a[i]]) % P;
    ans = (ans + 1ll * (P - f[0]) * (n - 1)) % P;
    ans = 1ll * ans * power(n, P - 2) % P;
    std::cout << ans << std::endl;
    return 0;
}