#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 3e5 + 5;
ll f[maxn], q[maxn], r[maxn];
ll fact[maxn], ifac[maxn];
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll n) { return qpow(n, mod - 2); }
int main() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  ifac[maxn - 1] = inv(fact[maxn - 1]);
  for (int i = maxn - 1; i; i--) ifac[i - 1] = ifac[i] * i % mod;
  f[0] = 1;
  f[1] = 1;
  int n = 100;
  ll sum = 4;
  for (int i = 2; i < maxn; i++) {
    f[i] = 1;
    // for (int j = 1; j < i; j++)
    // 1LL * (i - j) * f[i - j - 1]) % mod;
    f[i] = (sum - 1LL * (i)*f[i - 1]) % mod;
    sum = (sum + 1LL * (i + 1) * f[i]) % mod;
    // f[i]=f[i]
  }
  // printf("%d %d %d\n",f[2],f[3],f[4]);
  q[0] = 1;
  for (int i = 4; i < maxn; i += 4) {
    q[i] = 2 * (i / 2 - 1) * q[i - 4] % mod;
  }
  // for (int i = 0; i < n; i += 4) q[i] = f[i / 2];
  // printf("%lld\n", r[2]);
  // printf("%lld\n", r[3]);
  // printf("%lld\n", r[4]);
  // printf("%lld\n", r[5]);
  // printf("%lld\n", r[49]);
  // printf("%lld\n", (r[50] + mod) % mod);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll res = 0;
    for (int i = 0; i <= n; i++) {
      int j = n - i;
      res = (res + fact[i + j / 2] * ifac[j / 2] % mod * ifac[i] % mod * f[i] %
                       mod * q[j] % mod) %
            mod;
    }
    printf("%lld\n", (res + mod) % mod);
  }
  return 0;
}