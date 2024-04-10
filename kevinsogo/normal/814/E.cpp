#include <bits/stdc++.h>
using namespace std;

#define N 52
#define mod 1000000007
typedef long long ll;

int n;
int d[N];
map<ll,ll> memo;
ll f(int c1, int c2, int c3, int d1, int d2, int i) {
    if (c1 < 0 || c2 < 0 || c3 < 0 || d1 < 0 || d2 < 0) return 0;
    if (i == n) {
        return c1 == 0 && c2 == 0 && c3 == 0 && d1 == 0 && d2 == 0;
    }
    ll hsh = (((((((((ll(c1) << 6) | c2) << 6) | c3) << 2) | d1) << 6) | d2) << 6) | i;
    if (memo.count(hsh)) return memo[hsh];
    ll ans = 0;

    ans = (ans + c1 * f(c1 - 1, c2, c3, d1 + (d[i] == 2), d2 + (d[i] == 3), i + 1)) % mod;
    ans = (ans + c2 * f(c1 + 1, c2 - 1, c3, d1 + (d[i] == 2), d2 + (d[i] == 3), i + 1)) % mod;
    ans = (ans + c3 * f(c1, c2 + 1, c3 - 1, d1 + (d[i] == 2), d2 + (d[i] == 3), i + 1)) % mod;

    // ans = (ans + c1 * (c1 - 1) / 2 * f(c1 - 2, c2, c3, d1 + (d[i] == 3), d2, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) / 2 * f(c1 + 2, c2 - 2, c3, d1 + (d[i] == 3), d2, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) / 2 * f(c1, c2 + 2, c3 - 2, d1 + (d[i] == 3), d2, i + 1)) % mod;
    // ans = (ans + c1 * c2 * f(c1, c2 - 1, c3, d1 + (d[i] == 3), d2, i + 1)) % mod;
    // ans = (ans + c1 * c3 * f(c1 - 1, c2 + 1, c3 - 1, d1 + (d[i] == 3), d2, i + 1)) % mod;
    // ans = (ans + c2 * c3 * f(c1 + 1, c2, c3 - 1, d1 + (d[i] == 3), d2, i + 1)) % mod;
    ans = (ans + c1 * d1 * f(c1 - 1, c2, c3, d1 - 1 + (d[i] == 3), d2, i + 1)) % mod;
    ans = (ans + c2 * d1 * f(c1 + 1, c2 - 1, c3, d1 - 1 + (d[i] == 3), d2, i + 1)) % mod;
    ans = (ans + c3 * d1 * f(c1, c2 + 1, c3 - 1, d1 - 1 + (d[i] == 3), d2, i + 1)) % mod;
    ans = (ans + c1 * d2 * f(c1 - 1, c2, c3, d1 + 1 + (d[i] == 3), d2 - 1, i + 1)) % mod;
    ans = (ans + c2 * d2 * f(c1 + 1, c2 - 1, c3, d1 + 1 + (d[i] == 3), d2 - 1, i + 1)) % mod;
    ans = (ans + c3 * d2 * f(c1, c2 + 1, c3 - 1, d1 + 1 + (d[i] == 3), d2 - 1, i + 1)) % mod;

    // ans = (ans + c1 * (c1 - 1) * (c1 - 2) / 6 * f(c1 - 3, c2, c3, d1, d2, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) * (c2 - 2) / 6 * f(c1 + 3, c2 - 3, c3, d1, d2, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) * (c3 - 2) / 6 * f(c1, c2 + 3, c3 - 3, d1, d2, i + 1)) % mod;
    // ans = (ans + c1 * (c1 - 1) / 2 * c2 * f(c1 - 1, c2 - 1, c3, d1, d2, i + 1)) % mod;
    // ans = (ans + c1 * (c1 - 1) / 2 * c3 * f(c1 - 2, c2 + 1, c3 - 1, d1, d2, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) / 2 * c1 * f(c1 + 1, c2 - 2, c3, d1, d2, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) / 2 * c3 * f(c1 + 2, c2 - 1, c3 - 1, d1, d2, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) / 2 * c1 * f(c1 - 1, c2 + 2, c3 - 2, d1, d2, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) / 2 * c2 * f(c1 + 1, c2 + 1, c3 - 2, d1, d2, i + 1)) % mod;
    // ans = (ans + c1 * c2 * c3 * f(c1, c2, c3 - 1, d1, d2, i + 1)) % mod;

    // ans = (ans + c1 * (c1 - 1) / 2 * d1 * f(c1 - 2, c2, c3, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) / 2 * d1 * f(c1 + 2, c2 - 2, c3, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) / 2 * d1 * f(c1, c2 + 2, c3 - 2, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c1 * c2 * d1 * f(c1, c2 - 1, c3, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c1 * c3 * d1 * f(c1 - 1, c2 + 1, c3 - 1, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c2 * c3 * d1 * f(c1 + 1, c2, c3 - 1, d1 - 1, d2, i + 1)) % mod;
    // ans = (ans + c1 * (c1 - 1) / 2 * d2 * f(c1 - 2, c2, c3, d1 + 1, d2 - 1, i + 1)) % mod;
    // ans = (ans + c2 * (c2 - 1) / 2 * d2 * f(c1 + 2, c2 - 2, c3, d1 + 1, d2 - 1, i + 1)) % mod;
    // ans = (ans + c3 * (c3 - 1) / 2 * d2 * f(c1, c2 + 2, c3 - 2, d1 + 1, d2 - 1, i + 1)) % mod;
    // ans = (ans + c1 * c2 * d2 * f(c1, c2 - 1, c3, d1 + 1, d2 - 1, i + 1)) % mod;
    // ans = (ans + c1 * c3 * d2 * f(c1 - 1, c2 + 1, c3 - 1, d1 + 1, d2 - 1, i + 1)) % mod;
    // ans = (ans + c2 * c3 * d2 * f(c1 + 1, c2, c3 - 1, d1 + 1, d2 - 1, i + 1)) % mod;

    
    if (d[i] >= 3) {
        ans = (ans + c1 * d1 * (d1 - 1) / 2 * f(c1 - 1, c2, c3, d1 - 2, d2, i + 1)) % mod;
        ans = (ans + c2 * d1 * (d1 - 1) / 2 * f(c1 + 1, c2 - 1, c3, d1 - 2, d2, i + 1)) % mod;
        ans = (ans + c3 * d1 * (d1 - 1) / 2 * f(c1, c2 + 1, c3 - 1, d1 - 2, d2, i + 1)) % mod;
        ans = (ans + c1 * d2 * (d2 - 1) / 2 * f(c1 - 1, c2, c3, d1 + 2, d2 - 2, i + 1)) % mod;
        ans = (ans + c2 * d2 * (d2 - 1) / 2 * f(c1 + 1, c2 - 1, c3, d1 + 2, d2 - 2, i + 1)) % mod;
        ans = (ans + c3 * d2 * (d2 - 1) / 2 * f(c1, c2 + 1, c3 - 1, d1 + 2, d2 - 2, i + 1)) % mod;
        ans = (ans + c1 * d1 * d2 * f(c1 - 1, c2, c3, d1, d2 - 1, i + 1)) % mod;
        ans = (ans + c2 * d1 * d2 * f(c1 + 1, c2 - 1, c3, d1, d2 - 1, i + 1)) % mod;
        ans = (ans + c3 * d1 * d2 * f(c1, c2 + 1, c3 - 1, d1, d2 - 1, i + 1)) % mod;
    }

    if (c1 == 0 && c2 == 0 && c3 == 0) {
        ans = (ans + d1 * f(d1 - 1, d2, 0, (d[i] == 2), (d[i] == 3), i + 1)) % mod;
        ans = (ans + d2 * f(d1 + 1, d2 - 1, 0, (d[i] == 2), (d[i] == 3), i + 1)) % mod;

        // ans = (ans + d1 * (d1 - 1) / 2 * f(d1 - 2, d2, 0, (d[i] == 3), 0, i + 1)) % mod;
        // ans = (ans + d2 * (d2 - 1) / 2 * f(d1 + 2, d2 - 2, 0, (d[i] == 3), 0, i + 1)) % mod;
        // ans = (ans + d1 * d2 * f(d1, d2 - 1, 0, (d[i] == 3), 0, i + 1)) % mod;

        // if (d[i] >= 3) {
        //     ans = (ans + d1 * (d1 - 1) * (d1 - 2) / 6 * f(d1 - 3, d2, 0, 0, 0, i + 1)) % mod;
        //     ans = (ans + d1 * (d1 - 1) / 2 * d2 * f(d1 - 1, d2 - 1, 0, 0, 0, i + 1)) % mod;
        //     ans = (ans + d2 * (d2 - 1) / 2 * d1 * f(d1 + 1, d2 - 2, 0, 0, 0, i + 1)) % mod;
        //     ans = (ans + d2 * (d2 - 1) * (d2 - 2) / 6 * f(d1 + 3, d2 - 3, 0, 0, 0, i + 1)) % mod;
        // }
    }

    ans %= mod;
    return memo[hsh] = ans;
}
ll solve() {
    return f(0, d[0] == 2, d[0] == 3, 0, 0, 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    ll ans = solve();
    if ((ans %= mod) < 0) ans += mod;
    printf("%lld\n", ans);
}