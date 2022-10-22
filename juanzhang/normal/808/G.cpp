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

typedef long long ll;
const int maxn = 1e5 + 10;
char S[maxn], T[maxn];
int n, m, nxt[maxn], dp[2][maxn], pos[maxn][26];

int main() {
  scanf("%s %s", S + 1, T + 1);
  n = strlen(S + 1), m = strlen(T + 1);
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && T[i] != T[j + 1]) j = nxt[j];
    nxt[i] = j += T[i] == T[j + 1];
  }
  rep(i, 0, m - 1) rep(ch, 0, 25) pos[i][ch] = T[i + 1] == ch + 'a' ? i + 1 : pos[nxt[i]][ch];
  int sel = 1;
  memset(dp, -0x3f, sizeof dp);
  dp[0][0] = 0;
  rep(i, 1, n) {
    memset(dp[sel], -0x3f, (m + 1) << 2);
    rep(j, 0, m - 1) {
      rep(ch, 0, 25) if (S[i] == '?' || S[i] == ch + 'a') {
        chkmax(dp[sel][pos[j][ch]], dp[sel ^ 1][j]);
      }
    }
    chkmax(dp[sel][nxt[m]], dp[sel][m] + 1), sel ^= 1;
//    rep(j, 0, m - 1) printf("%d%c", dp[sel ^ 1][j], "\n "[j < m - 1]);
  }
  int res = 0;
  rep(i, 0, m - 1) chkmax(res, dp[sel ^ 1][i]);
  cout << res;
  return 0;
}