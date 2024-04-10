#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 500005, MOD = 998244353;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int t, n, a[MN], psa[MN], fact[MN], inv[MN];

int c(int n, int k) {
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int32_t main() {
    boost();

    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], psa[i] = a[i] + psa[i - 1];
        if (!psa[n]) {
            printf("%lld\n", fpow(2, n - 1));
            continue;
        }
        int ans = 0, l = 1, r = n, c1 = 0, c2 = 0;
        while (!a[l]) l++, c1++;
        while (!a[r]) r--, c2++;
        for (int i = 0; i <= min(c1, c2); i++) ans = (ans + c(c1, i) * c(c2, i) % MOD) % MOD;
        int suml = a[l], sumr = a[r];
        while (l <= r) {
            if (suml < sumr) suml += a[++l];
            else if (suml > sumr) sumr += a[--r];
            else if (l == r) break;
            else {
                int len1 = 1, len2 = 1;
                while (!a[l + 1]) l++, len1++;
                while (!a[r - 1]) r--, len2++;
                if (l >= r) {
                    ans = ans * fpow(2, len1) % MOD;
                } else {
                    int cnt = 0;
                    for (int i = 0; i <= min(len1, len2); i++) cnt = (cnt + c(len1, i) * c(len2, i) % MOD) % MOD;
                    ans = ans * cnt % MOD;
                    suml += a[++l];
                    sumr += a[--r];
                }
            }
        }
        ans %= MOD, ans += MOD, ans %= MOD;
        printf("%lld\n", ans);
    }

    return 0;
}