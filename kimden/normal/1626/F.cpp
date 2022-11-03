#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 998244353;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int sub(int x, int y) {
    int z = x + mod - y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}
inline int mul(int x, int y) {
    return (x * (ll)y) % mod;
}
inline int binpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = mul(ans, x);
        }
        x = mul(x, x);
        p >>= 1;
    }
    return ans;
}
inline int inv(int x) {
    return binpow(x, mod - 2);
}

const int ZU = 12252240;
int dp[2][ZU];

int p[140], q[140];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, x, y, k, m;
    cin >> n >> a >> x >> y >> k >> m;
    int ni = inv(n);
    int all_but_one = mul(n - 1, ni);
    int one = ni;
    for (int i = 0; i < ZU; ++i) {
        dp[0][i] = 0;
    }
    int nxt = 0;
    int cur = 1;
    for (int j = k; j >= 1; --j) {
        for (int i = 0; i < ZU; ++i) {
            dp[cur][i] = add(mul(all_but_one, dp[nxt][i]),
                             mul(ni, add(dp[nxt][i - i % j], i)));
        }
        cur ^= 1;
        nxt ^= 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int upper = a / ZU;
        int lower = a % ZU;
        int res = mul(mul(k, ni), mul(upper, ZU));
        res = add(res, dp[nxt][lower]);
        ans = add(ans, res);
        a = (a * (ll)x + y) % m;
    }
    ans = mul(ans, binpow(n, k));
    cout << ans << "\n";
}