#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 53;
const int M = 2510;
const int mod = 1e9 + 7;
void upd(int &x, int y) {
  (x += y) >= mod ? x -= mod : 0;
}
int n, m, a, b, c, sa, sbc, fac[N];
int f[N][M], g[N][N][M], h[N][N][N][3];
vector<int> v[3];
int main() {
  scanf("%d%d", &n, &m);
  int x, y;
  rep(i, 1, n) {
    scanf("%d%d", &x, &y);
    v[y - 1].pb(x);
  }
  *fac = 1;
  rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % mod;
  a = int(v[0].size());
  b = int(v[1].size());
  c = int(v[2].size());
  **f = 1;
  rep(i, 0, a - 1) {
    int x = v[0][i];
    per(j, i, 0)
      per(k, sa, 0)
        upd(f[j + 1][k + x], f[j][k]);
    sa += x;
  }
  ***g = 1;
  rep(i, 0, b - 1) {
    int x = v[1][i];
    per(j, i, 0)
      per(k, sbc, 0)
        upd(g[j + 1][0][k + x], g[j][0][k]);
    sbc += x;
  }
  rep(i, 0, c - 1) {
    int x = v[2][i];
    per(j, b, 0)
      per(_j, i, 0)
        per(k, sbc, 0)
          upd(g[j][_j + 1][k + x], g[j][_j][k]);
    sbc += x;
  }
  int ans = 0;
  h[1][0][0][0] = 1;
  h[0][1][0][1] = 1;
  h[0][0][1][2] = 1;
  rep(i, 0, a) {
    rep(j, 0, b) {
      rep(k, 0, c) {
        if(i + j + k > 1) {
          if(i) upd(h[i][j][k][0] = h[i - 1][j][k][1], h[i - 1][j][k][2]);
          if(j) upd(h[i][j][k][1] = h[i][j - 1][k][0], h[i][j - 1][k][2]);
          if(k) upd(h[i][j][k][2] = h[i][j][k - 1][0], h[i][j][k - 1][1]);
        }
        int q = 0, z = 0;
        upd(q, h[i][j][k][0]);
        upd(q, h[i][j][k][1]);
        upd(q, h[i][j][k][2]);
        rep(t, 0, m)
          z = (z + (ll)f[i][t] * g[j][k][m - t]) % mod;
        ans = (ans + (ll)z * q % mod * fac[i] % mod * fac[j] % mod * fac[k]) % mod;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}