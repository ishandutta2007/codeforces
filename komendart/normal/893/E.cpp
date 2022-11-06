#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxw = 1e6 + 1;
const int mod = 1e9 + 7;
const int maxlen = 20;

int dp[maxw][maxlen];

void precalc() {
    for (int i = 2; i < maxw; ++i) {
        dp[i][1] = 1;
    }
    for (int len = 1; len + 1 < maxlen; ++len) {
        for (int i = 2; i < maxw; ++i) {
            if (dp[i][len] == 0) continue;
            for (int j = i + i; j < maxw; j += i) {
                dp[j][len + 1] += dp[i][len];
                if (dp[j][len + 1] >= mod) dp[j][len + 1] -= mod;
            }
        }
    }
}

#define int long long

int binpow(int x, int p) {
    if (p == 0) return 1;
    if (p & 1) return x * binpow(x, p - 1) % mod;
    return binpow(x * x % mod, p >> 1);
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int fac[maxw];
int invfac[maxw];

void precalcfac() {
    fac[0] = 1;
    for (int i = 1; i < maxw; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[maxw - 1] = inv(fac[maxw - 1]);
    for (int i = maxw - 2; i >= 0; --i) {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }
}

int cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    precalc();
    precalcfac();
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        signed x, y;
        cin >> x >> y;
        int ans = 0;
        for (int len = 1; len < maxlen; ++len) {
            ans += dp[x][len] * cnk(y, len);
            ans %= mod;
        }
        if (x == 1) ans = 1;
        ans = ans * binpow(2, y - 1) % mod;
        cout << ans << '\n';
    }
    
    
}