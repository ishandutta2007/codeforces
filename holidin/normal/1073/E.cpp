#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2e3 + 1;
const int LogN = 20;

long long dp[20][N][10], dps[20][N][10], t[LogN], z[LogN];

int len(long long x) {
    int cnt = 0;
    if (x == 0)
        return 1;
    while (x > 0) {
        x /= 10;
        ++cnt;
    }
    return cnt;
}
int cnt_bit(int x) {
    int ans = 0;
    for (int i = 0; i < 10; ++i)
    if ((x & t[i]) > 0)
        ++ans;
    return ans;
}

long long f(long long r, int k) {
    int i, j, l, p;
    long long btm = 0, ans = 0, y = 0;
    int c = len(r);
    long long u = 1;
    for (i = 1; i < c; ++i)
        u *= 10;
    for (i = 1; i < c; ++i)
    for (j = 0; j < t[10]; ++j)
    for (p = 1; p < 10; ++p)
    if (cnt_bit(j) <= k)
        ans += dps[i][j][p] % mod;
    for (i = c; i > 0; --i) {
        int ct = 0, ck = r / u;
        if (i == c)
            ct = 1;
        if (i == 1)
            ++ck;
        for (j = 0; j < t[10]; ++j)
        for (l = ct; l < ck; ++l)
        if (cnt_bit(j | btm) <= k)
            ans += (dps[i][j][l] + dp[i][j][l] * ((y * z[i]) % mod)) % mod;
        btm |= t[r / u];
        y = y * 10 + r / u;
        r %= u;
        u /= 10;
    }
    return ans;
}

int main() {
    int i, j, k, p, n;
    long long l, r;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    dp[0][0][0] = 1;
    t[0] = 1;
    z[0] = 1;
    for (i = 1; i < LogN; ++i) {
        t[i] = t[i - 1] * 2;
        z[i] = (z[i - 1] * 10) % mod;
    }
    for (i = 0; i <= 18; ++i)
    for (j = 0; j < t[10]; ++j)
    for (l = 0; l <= 9; ++l)
    for (p = 0; p <= 9; ++p) {
        dp[i + 1][j | t[p]][p] = (dp[i + 1][j | t[p]][p] + dp[i][j][l]) % mod;
        dps[i + 1][j | t[p]][p] = (dps[i + 1][j | t[p]][p] + dps[i][j][l] + dp[i][j][l] * ((z[i] * (long long) p) % mod)) % mod;
    }
    cin >> l >> r >> k;
    cout << (f(r, k) - f(l - 1, k) + mod * mod) % mod;

}