#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, f[N], invf[N];
ll C(int n, int m) {
  if (m > n) return 0;
  return 1ll * f[n] * invf[m] % mod * invf[n - m] % mod;
}
int main() {
  // freopen("1.in", "r", stdin);
  f[0] = invf[0] = f[1] = invf[1] = 1;
  for (int i = 2; i < N; i++)
    f[i] = 1ll * f[i - 1] * i % mod,
    invf[i] = 1ll * (mod - mod / i) * invf[mod % i] % mod;
  for (int i = 2; i < N; i++) invf[i] = 1ll * invf[i - 1] * invf[i] % mod;
  scanf("%d", &n);
  if (n == 1) {
    printf("2\n");
    return 0;
  }
  ll ans = 0;
  for (int i = (n + 1) / 2 + (n + 1) / 2 % 2; i <= n; i += 2) {
    assert(i >= n - i);
    ans = (ans + 2ll * C(i, n - i) % mod * f[i] % mod) % mod;
    if (n - i - 1 >= 0)
      ans = (ans + 2ll * C(i - 1, n - i - 1) % mod * f[i] % mod) % mod;
  }
  printf("%lld\n", ans);
}
/*
69420
629909355

42069
675837193
*/