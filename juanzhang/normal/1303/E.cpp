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

const int maxn = 405;
char S[maxn], T[maxn];
int n, m, nxt[maxn][26];

bool DP(int len) {
  static int dp[maxn][maxn];
  memset(dp, -0x3f, sizeof dp);
  dp[0][0] = 0;
  rep(i, 0, n) {
    rep(j, 0, len) {
      if (j < len) chkmax(dp[nxt[i][T[j + 1] - 'a']][j + 1], dp[i][j]);
      if (dp[i][j] >= 0 && dp[i][j] < m - len) chkmax(dp[nxt[i][T[len + dp[i][j] + 1] - 'a']][j], dp[i][j] + 1);
    }
    if (dp[i][len] == m - len) {
      return 1;
    }
  }
  return 0;
}

void solve() {
  scanf("%s %s", S + 1, T + 1);
  n = strlen(S + 1), m = strlen(T + 1);
  int lst[26];
  fill(lst, lst + 26, n + 1);
  per(i, n, 0) {
    memcpy(nxt[i], lst, sizeof lst);
    lst[S[i] - 'a'] = i;
  }
  rep(i, 1, m) {
    if (DP(i)) {
      puts("YES"); return;
    }
  }
  puts("NO");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}