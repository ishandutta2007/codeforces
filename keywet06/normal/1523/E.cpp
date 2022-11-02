#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL fac[100005], ifac[100005];
LL QuickPow(LL x, LL p) {
    LL ans = 1, base = x;
    while (p) {
        if (p & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        p >>= 1;
    }
    return ans;
}
LL C(LL n, LL m) {
    if (n < m) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}
int main() {
    fac[0] = 1;
    for (LL i = 1; i <= 100000; ++i) fac[i] = fac[i - 1] * i % MOD;
    ifac[100000] = QuickPow(fac[100000], MOD - 2);
    for (LL i = 99999; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    LL T;
    scanf("%lld", &T);
    while (T-- > 0) {
        LL n, k;
        scanf("%lld %lld", &n, &k);
        LL ans = 1;
        for (LL i = 1; i < n; ++i)
            (ans += C(n - (i - 1) * (k - 1), i) * QuickPow(C(n, i), MOD - 2)) %=
                MOD;
        printf("%lld\n", ans);
    }
    return 0;
}