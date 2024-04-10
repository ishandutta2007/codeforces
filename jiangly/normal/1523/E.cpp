#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int P = 1000000007, N = 100000;
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
    std::vector<int> fac(N + 1), invfac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = i64(fac[i - 1]) * i % P;
    }
    invfac[N] = power(fac[N], P - 2);
    for (int i = N; i; i--) {
        invfac[i - 1] = i64(invfac[i]) * i % P;
    }
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        k--;
        int ans = 1;
        for (int i = 0; n - i * k >= i + 1; i++) {
            ans = (ans + i64(fac[n - i * k]) * invfac[n - i * k - i - 1] % P * invfac[n] % P * fac[n - i - 1]) % P;
        }
        std::cout << ans << "\n";
    }
    return 0;
}