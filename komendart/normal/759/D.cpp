#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxc = 26;
const int MOD = 1e9 + 7;
const int maxn = 5005;

int n;
int dp[maxc][maxn];
int sum[maxn];
int a[maxn];

int power(int x, int p) {
    assert(p >= 0);
    if (p == 0) return 1;
    if (p % 2 == 1) return x * power(x, p - 1) % MOD;
    return power(x * x % MOD, p / 2);
}

int inv(int x) {
    return power(x, MOD - 2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int len;
    cin >> len;
    string s;
    cin >> s;
    for (int i = 0; i < len; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            a[n++] = s[i] - 'a';
        }
    }
    sum[0] = 1;

    for (int i = 0; i < n; ++i) {
        int c = a[i];
        for (int k = i + 1; k > 0; --k) {
            int cur = (sum[k - 1] - dp[c][k - 1]) % MOD;
            if (cur < 0) cur += MOD;
            sum[k] -= dp[c][k];
            dp[c][k] = cur;
            sum[k] += cur;
            sum[k] %= MOD;
            if (sum[k] < 0) sum[k] += MOD;
        }
    }

    vector<int> fac(maxn, 1);
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= len; ++i) {
        //cerr << ' ' << len - 1 << ' ' << i - 1 << ' ' << len - i << endl;
        int C = fac[len - 1] * inv(fac[i - 1]) % MOD * inv(fac[len - i]) % MOD;
        ans += C * sum[i];
        //cerr << i << ' ' << sum[i] << ' ' << C << endl;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}