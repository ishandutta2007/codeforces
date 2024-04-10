#include <bits/stdc++.h>

const int P = 998244353;

int power(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a = int64_t(a) * a % P)
        if (b % 2 == 1) res = int64_t(res) * a % P;
    return res;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::vector<int> cnt(n);
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && 2 * a[j] <= a[i]) ++j;
        cnt[i] = n - j;
    }
    std::vector<int> dp(n), suf(n + 1), fac(n + 1), invFac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = int64_t(fac[i - 1]) * i % P;
    invFac[n] = power(fac[n], P - 2);
    for (int i = n - 1; i >= 0; --i) invFac[i] = int64_t(invFac[i + 1]) * (i + 1) % P;
    int ans = 0;
    for (int i = n - 1, j = n; i >= 0; --i) {
        while (a[j - 1] >= 2 * a[i]) --j;
        if (cnt[i] == 1) dp[i] = 1;
        else if (j < n) dp[i] = int64_t(suf[j]) * fac[cnt[i] - 2] % P;
        suf[i] = (suf[i + 1] + int64_t(dp[i]) * invFac[cnt[i] - 1]) % P;
        ans = (ans + int64_t(dp[i]) * fac[n - 1] % P * invFac[cnt[i] - 1]) % P;
    }
    std::cout << ans << "\n";
    
    return 0;
}