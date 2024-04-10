#include <bits/stdc++.h>
using i64 = long long;
constexpr int P = 1000000007;
int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = i64(a) * a % P) {
        if (b % 2) {
            res = i64(res) * a % P;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i64(fac[i - 1]) * i % P;
    }
    invfac[n] = power(fac[n], P - 2);
    for (int i = n; i; i--) {
        invfac[i - 1] = i64(invfac[i]) * i % P;
    }
    int ans = 0;
    for (int i = (n - 1) / 4 + 1; 2 * i <= n; i++) {
        ans = (ans + 2ll * n * fac[2 * i - 1] % P * fac[2 * i] % P * invfac[n - 2 * i] % P * invfac[4 * i - n]) % P;
    }
    std::cout << ans << "\n";
    return 0;
}