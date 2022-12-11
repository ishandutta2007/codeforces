#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 3005;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int n, a, b, p, q, pm[N], qm[N];
int cs[N][N], con[N], f[N];
int main() {
  scanf("%d%d%d", &n, &a, &b);
  p = (ll)a * qpow(b, mod - 2) % mod;
  q = (mod + 1 - p) % mod;
  pm[0] = qm[0] = 1;
  rep(i, 1, n) pm[i] = (ll)pm[i - 1] * p % mod;
  rep(i, 1, n) qm[i] = (ll)qm[i - 1] * q % mod;
  rep(i, 0, n) cs[i][0] = cs[0][i] = 1;
  rep(i, 1, n) rep(j, 1, n - i)
    cs[i][j] = ((ll) qm[j] * cs[i - 1][j] + (ll) pm[i] * cs[i][j - 1]) % mod;
  rep(i, 1, n) {
    con[i] = 1;
    rep(k, 1, i - 1) {
      con[i] = (con[i] + (mod - con[k]) * (ll)cs[k][i - k]) % mod;
    }
  }
  f[1] = 0;
  rep(i, 2, n) {
    f[i] = con[i] * (i * (i - 1ll) / 2) % mod;
    rep(k, 1, i - 1) {
      f[i] = (f[i] + (ll)cs[k][i - k] * con[k] % mod * (f[i - k] + f[k] + (k * (k - 1) / 2))) % mod;
    }
    f[i] = (ll)f[i] * qpow(mod + 1 - con[i], mod - 2) % mod;
  }
  (f[n] += n * (n - 1) / 2) %= mod;
  printf("%d\n", f[n]);
  return 0;
}