#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
ll inv[maxn];
int a[maxn];
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
  int tt;
  scanf("%d", &tt);
  inv[1] = 1;
  for (int i = 2; i < maxn; i++) inv[i] = -mod / i * inv[mod % i] % mod;
  while (tt--) {
    int n;
    scanf("%d", &n);
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      (a[i] ? c1 : c0)++;
    }
    int rm = 0;
    for (int i = 0; i < c0; i++) rm += a[i];
    // printf("%d\n", rm);
    ll ans = 0;
    for (int i = 1; i <= rm; i++) {
      int iv = inv[i];
      ans = (ans + 1LL * n * (n - 1) / 2 % mod * iv % mod * iv % mod) % mod;
    }
    printf("%lld\n", (ans % mod + mod) % mod);
  }
  return 0;
}