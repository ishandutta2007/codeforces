#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        x = x * 1ll * x % mod;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p1(n + 1, 1), p2(n + 1, 1);
    p1[1] = a * 1ll * inv(b) % mod;
    p2[1] = (b - a) * 1ll * inv(b) % mod;
    for (int i = 2; i <= n; i++) {
        p1[i] = p1[i - 1] * 1ll * p1[1] % mod;
        p2[i] = p2[i - 1] * 1ll * p2[1] % mod;
    }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] * 1ll * p1[j] + dp[i - 1][j - 1] * 1ll * p2[i - j]) % mod;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    vector<int> c(n + 1);
    c[0] = c[1] = 1;
    for (int i = 2; i <= n; i++) {
        c[i] = 1;
        for (int j = 1; j <= i - 1; j++) {
            c[i] = (c[i] - dp[i][j] * 1ll * c[j] % mod + mod) % mod;
        }
    }
    vector<int> ans(n + 1);
    ans[0] = ans[1] = 0;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int k = 1; k <= i; k++) {
            int res = c[k] * 1ll * dp[i][k] % mod;
            int res2 = (k * 1ll * (i - k) + k * 1ll * (k - 1) / 2 + ans[i - k]) % mod;
            if (k != i) {
                res2 = (res2 + ans[k]) % mod;
            }
            sum = (sum + res * 1ll * res2) % mod;
        }
        int d = (1 - c[i] * 1ll * dp[i][i] % mod + mod) % mod;
        ans[i] = sum * 1ll * inv(d) % mod;
    }
    cout << ans[n];
}