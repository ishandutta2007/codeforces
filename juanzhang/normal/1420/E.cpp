#pragma GCC optimize(3)

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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
int n, A[85], pos[85];

int dp[2][85][3205];

void solve() {
  cin >> n;
  int m = 0, cnt = 0, all = n * (n - 1) / 2;
  rep(i, 1, n) {
    A[i] = read();
    if (A[i] == 1) pos[++m] = i;
  }
  cnt = n - m;
  memset(dp, 0x3f, sizeof dp);
  dp[0][0][0] = 0;
  int sel = 1;
  rep(i, 1, m) {
    rep(j, i, n) rep(k, 0, all) {
      int t = k - abs(j - pos[i]);
      if (t < 0) continue;
      rep(j2, i - 1, n) if (j != j2) {
        int l = abs(j - j2 - 1);
        chkmin(dp[sel][j][k], dp[sel ^ 1][j2][t] + l * (l - 1) / 2);
      }
    }
    sel ^= 1;
  }
  int res = 1e9;
  rep(k, 0, all) {
    rep(i, 0, n) chkmin(res, dp[sel ^ 1][i][k] + (n - i) * (n - i - 1) / 2);
    printf("%d ", cnt * (cnt - 1) / 2 - res);
  }
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}