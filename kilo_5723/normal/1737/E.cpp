#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll dp[maxn * 2];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll sum = 0;
    int l = n + 1, r = 2 * n - 1;
    fill(dp, dp + 2 * n + 2, 0);
    for (int i = n; i >= 1; i--) {
      while (l > i + 1) sum += dp[--l];
      while (r > 2 * i) sum -= dp[--r];
      sum %= mod;
      dp[i] = (i > n - i) + sum;
    }
    ll base = qpow(qpow(2, n), mod - 2);
    for (int i = 1; i <= n; i++) {
      ll a = qpow(2, i / 2), b = dp[i];
      if (i == n) base = base * 2 % mod;
      ll ans = base * a % mod * b % mod;
      printf("%lld\n", (ans % mod + mod) % mod);
    }
  }
  return 0;
}