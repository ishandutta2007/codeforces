#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

// #define int long long
typedef long long ll;

const int N = 405;
const int mod = 998244353;

#define ADD(u, v) u = ((u) + (v)) % mod

int n, c[32], ans, f[N][N][2][2], g[4][N][N][3][3];
signed main() {
  scanf("%d", &n);
  rep(i, 1, 26) scanf("%d", c + i);
  ans = 1;
  rep(i, 1, n) ans = ans * (i <= 2 ? 26ll : 25ll) % mod;
  f[2][0][0][0] = 25 * 25;
  f[2][1][1][0] = 25;
  f[2][1][0][1] = 25;
  f[2][2][1][1] = 1;
  rep(i, 3, n) {
    int t;
    rep(j, 0, i - 1) rep(u, 0, 1) rep(v, 0, 1) if((t = f[i - 1][j][u][v]) > 0) {
      if(!u) ADD(f[i][j + 1][v][1], t);
      ADD(f[i][j][v][0], (ll)t * (u ? 25 : 24));
    }
  }

  rep(u, 0, 2) rep(v, 0, 2) g[2][(u == 1) + (v == 1)][(u == 2) + (v == 2)][u][v] = (u ? 1 : 24) * (v ? 1 : 24);
  int cur = 2;
  rep(i, 3, n) {
    // cur = cur + 1;
    // int cc = cur - 1;
    cur = (cur + 1) & 3;
    int cc = (cur + 3) & 3;
    memset(g[cur], 0, sizeof g[cur]);
    int t;
    rep(j, 0, i - 1) rep(k, 0, i - 1 - j) rep(u, 0, 2) rep(v, 0, 2) if((t = g[cc][j][k][u][v]) > 0) {
      rep(w, 0, 2) if(!w || w != u) {
        ADD(g[cur][j + (w == 1)][k + (w == 2)][v][w], w ? t : (t * (u ? 24ll : 23ll)));
      }
    }
  }

  rep(i, 1, 26) {
    rep(j, c[i] + 1, n) {
      int t = ( (ll)f[n][j][0][0] + (ll) f[n][j][0][1] + (ll) f[n][j][1][0] + (ll)f[n][j][1][1] ) % mod;
      ans = (ans + mod - t) % mod;
    }
  }

  // rep(i, 1, 26) {
  //   rep(_i, i + 1, 26) {
  //     int res = 0;
  //     rep(j, c[i] + 1, n) {
  //       rep(_j, c[_i] + 1, n - j) {
  //         int t = 0;
  //         rep(u, 0, 2) rep(v, 0, 2) ADD(t, g[cur][j][_j][u][v]);
  //         ADD(res, t);
  //       }
  //     }
  //     // printf("res(%d,%d) = %d\n", i, _i, res);
  //   }
  // }
  rep(i, 1, 26) {
    rep(j, c[i] + 1, n) {
      rep(_i, i + 1, 26) {
        rep(_j, c[_i] + 1, n - j) {
          int t = 0;
          rep(u, 0, 2) rep(v, 0, 2) ADD(t, g[cur][j][_j][u][v]);
          ans = (ans + t) % mod;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}