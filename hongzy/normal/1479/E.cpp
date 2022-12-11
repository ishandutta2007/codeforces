#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 1024, mod = 998244353;
int inv(int a, int b = mod - 2) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int m, n, a[N], frac[N][2];
int main() {
  scanf("%d", &m);
  rep(i, 1, m) scanf("%d", a + i), n += a[i];
  if(m == 1) { puts("0"); return 0; }
  sort(a + 1, a + m + 1);
  a[m + 1] = n;
  int p = 0, f[4] = {-2, 1}, g[4] = {0, 1}, h[4];
  while(a[p + 1] == 1) ++ p, *frac[p] = -2, *(frac[p]+1) = 1;
  rep(i, 1, n - 1) {
    *h = ((3ll * n - 2 * i) * *f % mod * *(g+1) - (2ll * n - i) * *g % mod * *(f+1)) % mod;
    *(h+1) = 1ll * (n - i) * *(f+1) % mod * *(g+1) % mod;
    *g = *f, *(g+1) = *(f+1);
    *f = *h, *(f+1) = *(h+1);
    while(a[p + 1] == i + 1) ++ p, *frac[p] = *f, *(frac[p]+1) = *(f+1);
  }
  int ans = - *frac[m + 1] * (ll)inv(*(frac[m + 1]+1)) % mod;
  rep(i, 1, m)
    ans = (ans + (ll)*frac[i] * inv(*(frac[i] + 1))) % mod;
  if(ans < 0) ans += mod;
  printf("%d\n", ans);
  return 0;
}