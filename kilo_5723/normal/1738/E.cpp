#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int a[maxn];
ll fact[maxn], ifac[maxn];
ll comb(int a, int b) { return fact[a] * ifac[b] % mod * ifac[a - b] % mod; }
ll solve(int a, int b) {
  // printf("%d %d: ", a, b);
  ll res = 0;
  for (int i = 0; i <= a && i <= b; i++)
    res = (res + comb(a, i) * comb(b, i) % mod) % mod;
  // printf("%lld\n", res);
  return res;
}
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  ifac[maxn - 1] = qpow(fact[maxn - 1], mod - 2);
  for (int i = maxn - 1; i; i--) ifac[i - 1] = ifac[i] * i % mod;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int p = 0, q = n - 1;
    ll ans = 1, cnt = 1;
    bool flg = true;
    while (p <= q) {
      int p0 = p, q0 = q;
      while (p < n && a[p] == 0) p++;
      while (q >= 0 && a[q] == 0) q--;
      if (p > q) {
        // printf("break %d %d\n", p, q);
        ans = ans * qpow(2, p - q - flg * 2) % mod;
        break;
      }
      ans = ans * (solve(p - p0 + 1 - flg, q0 - q + 1 - flg)) % mod;
      flg = false;
      ll sa = a[p++], sb = a[q--];
      while (sa != sb) {
        if (sa < sb)
          sa += a[p++];
        else
          sb += a[q--];
      }
      if (p == q + 1) ans = ans * 2 % mod;
      if (p > q) break;
    }
    printf("%lld\n", ans);
  }
  return 0;
}