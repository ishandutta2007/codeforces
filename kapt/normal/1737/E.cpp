#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 0) {
            x = (x * x) % MOD;
            n /= 2;
        } else {
            res = (res * x) % MOD;
            n--;
        }
    }
    return res;
}

const int MAXN = 1e6 + 100;
int p[MAXN], invp[MAXN];

main() {
    p[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        p[i] = (p[i - 1] * 2) % MOD;
    }
    invp[MAXN - 1] = binpow(p[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i > 0; --i) {
        invp[i - 1] = (invp[i] * 2) % MOD;
    }
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> dp(n);
        dp[n - 1] = 2;
        int sum = 0;
        for (int i = n - 2; i >= 0; --i) {
            sum = (sum * invp[1]) % MOD;
            for (int k = 2 * i + 1; k <= 2 * i + 2; ++k) {
                if (k >= n) continue;
                sum -= (dp[k] * invp[k - i]) % MOD;
                sum = (sum % MOD + MOD) % MOD;
            }
            sum += dp[i + 1] * invp[1];
            sum %= MOD;
            dp[i] = sum;
        }
        for (int i = 0; i < n; ++i) {
            int pr = invp[i / 2 + 1];
            pr = (pr * dp[i]) % MOD;
            cout << pr << '\n';
        }
    }
    return 0;
}