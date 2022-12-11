#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, k, p, w, cnt[N], f[21][N], g[21][N], fav[N];
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % p)
    if(b & 1) ans = (ll)ans * a % p;
  return ans;
}
void upd(int &a, int b) { (a += b) >= p ? a -= p : 0; }
void fwt(int *a) {
  for(int i = 1; i < (1 << w); i <<= 1)
    for(int j = 0; j < (1 << w); j += i << 1)
      for(int k = 0; k < i; k ++)
        upd(a[j + k + i], a[j + k]);
}
void ifwt(int *a) {
  for(int i = 1; i < (1 << w); i <<= 1)
    for(int j = 0; j < (1 << w); j += i << 1)
      for(int k = 0; k < i; k ++)
        upd(a[j + k + i], p - a[j + k]);
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  if(n & 1) return printf("%d\n", qpow(k, n)), 0;
  rep(i, 1, n) cnt[i] = cnt[i & (i - 1)] + 1;
  for(int i = 0; i < 21; i ++) if(n & (1 << i)) w = i;
  w ++;
  fav[0] = fav[1] = 1;
  rep(i, 2, n) fav[i] = (ll)fav[p % i] * (p - p / i) % p;
  rep(i, 1, n) fav[i] = (ll)fav[i - 1] * fav[i] % p;
  rep(i, 0, n) g[cnt[i]][i] = fav[i];
  rep(i, 1, w) fwt(g[i]);
  fill(g[0], g[0] + (1 << w), 1);
  fill(f[0], f[0] + (1 << w), 1);
  for(int z = k; z; z >>= 1) {
    if(z & 1) {
      per(i, w, 0) rep(j, 0, i - 1)
        rep(u, 0, (1 << w) - 1)
          f[i][u] = (f[i][u] + (ll)f[j][u] * g[i - j][u]) % p;
    }
    per(i, w, 0) rep(j, 0, i - 1)
      rep(u, 0, (1 << w) - 1)
        g[i][u] = (g[i][u] + (ll)g[j][u] * g[i - j][u]) % p;
  }
  ifwt(f[cnt[n]]);
  int res = f[cnt[n]][n];
  rep(i, 1, n) res = (ll)res * i % p;
  printf("%d\n", (qpow(k, n) + p - res) % p);
  return 0;
}