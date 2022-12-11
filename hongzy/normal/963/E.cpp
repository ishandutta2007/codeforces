#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
#define pd(a, b) a = (ll)a * b % mod
const int mod = 1e9 + 7;
const int N = 105;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, pd(a, a))
    if(b & 1) pd(ans, a);
  return ans;
}
int sqr(int x) { return x * x; }
int R, p1, p2, p3, p4, h[N], c[N][N][N];
//[1, 2R + 1] & R + 1
int a[N][N];
void gauss(int n) {
  // rep(i, 1, n) rep(j, 1, n + 1) printf("%d%c", a[i][j], " \n"[j == n + 1]);
  static int w[N];
  rep(i, 1, n) {
    int j = i;
    rep(k, i, n) if(a[k][i]) { j = k; break ; }
    if(j != i) {
      rep(k, i, n + 1) swap(a[j][k], a[i][k]);
    }
    w[i] = qpow(a[i][i], mod - 2);
    for(j = i + 1; j <= n; j ++) {
      int t = (mod - a[j][i]) * (ll)w[i] % mod;
      rep(k, i, n + 1)
        a[j][k] = (a[j][k] + (ll)t * a[i][k]) % mod;
    }
  }
  per(i, n, 1) {
    rep(j, i + 1, n)
      a[i][n + 1] = (a[i][n + 1] + (mod - a[i][j]) * (ll)a[j][n + 1]) % mod;
    a[i][n + 1] = (ll)a[i][n + 1] * w[i] % mod;
  }
}
int main() {
  scanf("%d%d%d%d%d", &R, &p1, &p2, &p3, &p4);
  int s = qpow(p1 + p2 + p3 + p4, mod - 2);
  pd(p1, s); pd(p2, s); pd(p3, s); pd(p4, s);
  int ip2 = qpow(p2, mod - 2);
  int w = R << 1 | 1;
  rep(i, 1, w) h[i] = (ll)floor(sqrt(sqr(R) - sqr(i - R - 1)));
  rep(i, 1, w) c[i][i][R + 1 + h[i]] = 1;
  rep(i, 1, w + 1) per(y, w, 1) rep(x, 1, w) {
    if(y > R + 1 + h[x] || y <= R + 1 - h[x])
      continue ;
    c[i][x][y - 1] = (c[i][x][y] + (i == w + 1 ? mod - 1 : 0) + (ll)(mod - p1) * c[i][x - 1][y]
      + (ll)(mod - p3) * c[i][x + 1][y]
      + (ll)(mod - p4) * c[i][x][y + 1]) % mod * ip2 % mod;
  }
  rep(x, 1, w) {
    int y = R + 1 - h[x];
    rep(i, 1, w + 1) {
      a[x][i] = ( (mod - c[i][x][y]) + (ll)p1 * c[i][x - 1][y] + (ll)p2 * c[i][x][y - 1] + (ll)p3 * c[i][x + 1][y] + (ll)p4 * c[i][x][y + 1] + (i == w + 1) ) % mod;
    }
    a[x][w + 1] = (mod - a[x][w + 1]) % mod;
  }
  gauss(w);
  int ans = c[w + 1][R + 1][R + 1];
  rep(i, 1, w) ans = (ans + (ll)c[i][R + 1][R + 1] * a[i][w + 1]) % mod;
  printf("%d\n", ans);
  return 0;
}