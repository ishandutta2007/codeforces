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
const int maxn = 505;
int n, a[maxn], dp[maxn], f[maxn][maxn], g[maxn][maxn];

int main() {
  cin >> n;
  rep(i, 1, n) a[i] = read(), f[i][i] = 1, g[i][i] = a[i];
  rep(len, 2, n) rep(i, 1, n - len + 1) {
    int j = i + len - 1;
    rep(k, i, j - 1) if (f[i][k] && f[k + 1][j] && g[i][k] == g[k + 1][j]) {
      f[i][j] = 1, g[i][j] = g[i][k] + 1;
    }
  }
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  rep(i, 1, n) rep(j, 0, i - 1) if (f[j + 1][i]) {
    chkmin(dp[i], dp[j] + 1);
  }
  cout << dp[n];
  return 0;
}