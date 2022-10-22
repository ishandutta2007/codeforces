#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 505;
int n, m, k, lef[maxn], rig[maxn], a[maxn][maxn], dp[maxn][maxn], val[maxn][maxn];

int main() {
  cin >> n >> m >> k;
  rep(i, 1, n) rep(j, 1, m) scanf("%1d", &a[i][j]);
  rep(i, 1, n) {
    memset(val[i], 0x3f, sizeof val[i]);
    int cnt = 0;
    rep(j, 1, m) cnt += a[i][j] == 1, lef[j] = lef[j - 1] + (a[i][j] == 1);
    per(j, m, 1) rig[j] = rig[j + 1] + (a[i][j] == 1);
    int lpos = 0, rpos = 0;
    rep(j, 1, m) if (a[i][j]) {
      if (!lpos) lpos = j;
      rpos = j;
    }
    val[i][cnt] = 0;
    val[i][0] = cnt ? rpos - lpos + 1 : 0;
    rep(l, 1, m) rep(r, l, m) {
      if (a[i][l] != 1 || a[i][r] != 1) continue;
      int s = lef[l - 1] + rig[r + 1];
      chkmin(val[i][s], r - l + 1);
    }
  }
  int res = INT_MAX;
  memset(dp, 0x3f, sizeof dp);
  dp[0][0] = 0;
  rep(i, 1, n) {
    rep(j, 0, k) {
      rep(t, 0, j) {
        chkmin(dp[i][j], dp[i - 1][t] + val[i][j - t]);
      }
    }
  }
  rep(i, 0, k) chkmin(res, dp[n][i]);
  cout << res;
  return 0;
}