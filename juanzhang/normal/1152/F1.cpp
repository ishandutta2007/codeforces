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

const int P = 1e9 + 7;
int n, k, m, dp[2][13][1 << 4];

inline void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

int main() {
  n = read(), k = read(), m = read();
  int sel = 0, ans = 0, all = (1 << m) - 1;
  dp[0][0][0] = 1;
  per(i, n + 1, 1) {
    memset(dp[sel ^ 1], 0, sizeof dp[sel ^ 1]);
    rep(j, 0, k) {
      rep(S, 0, all) {
        int T = S << 1 & all;
        int val = dp[sel][j][S];
        Add(dp[sel ^ 1][j][T], val);
        if (j < k) {
          Add(dp[sel ^ 1][j + 1][T | 1], 1ll * (1 + __builtin_popcount(S)) * val % P);
        }
      }
    }
    rep(S, 0, 1 << m) if (S & 1) {
      Add(ans, dp[sel][k][S]);
    }
    sel ^= 1;
  }
  printf("%d", ans);
  return 0;
}