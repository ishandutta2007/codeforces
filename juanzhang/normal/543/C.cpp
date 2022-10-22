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

char str[20][20];
int n, m, cost[20][20], dp[1 << 20];

int state[20][20], val[20][20];

int main() {
  scanf("%d %d", &n, &m);
  rep(i, 0, n - 1) scanf("%s", str[i]);
  rep(i, 0, n - 1) rep(j, 0, m - 1) {
    scanf("%d", &cost[i][j]);
  }
  rep(i, 0, n - 1) rep(j, 0, m - 1) {
    int sum = 0, mx = 0;
    rep(k, 0, n - 1) if (str[i][j] == str[k][j]) {
      state[i][j] |= 1 << k;
      sum += cost[k][j], chkmax(mx, cost[k][j]);
    }
    val[i][j] = sum - mx;
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  rep(S, 0, (1 << n) - 2) {
    int i;
    rep(j, 0, n - 1) {
      if (~S >> j & 1) {
        i = j; break;
      }
    }
    rep(j, 0, m - 1) {
      chkmin(dp[S | 1 << i], dp[S] + cost[i][j]);
      chkmin(dp[S | state[i][j]], dp[S] + val[i][j]);
    }
  }
  printf("%d", dp[(1 << n) - 1]);
  return 0;
}