#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll qp(ll x, ll n) {
    return !n ? 1 : qp(x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod;
}
ll inv(ll x) {return qp(x, mod - 2);}
ll C(ll n, ll m) {
    if (n < 0 || n < m || m < 0) return 0;
    ll res = 1, div = 1;
    for (ll i = n; i > n - m; -- i) (res *= i % mod) %= mod;
    for (ll i = m; i; -- i) (div *= i % mod) %= mod;
    return res * inv(div) % mod;
}
int n;
ll s, f[25];
map <ll, ll> dp[25];
ll DP(int i, ll x) {
    if (x < 0) return 0;
    if (i < 0) return C(x + n - 1, n - 1);
    if (dp[i].count(x)) return dp[i][x];
    ll res = (DP(i - 1, x) - DP(i - 1, x - f[i] - 1) + mod) % mod;
    return dp[i][x] = res;
}
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++ i) cin >> f[i];
    cout << DP(n - 1, s) << endl;
    return 0;
}