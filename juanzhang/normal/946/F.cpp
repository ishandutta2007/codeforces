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

const int maxn = 105, P = 1e9 + 7;
int n, m, a[maxn], sum[maxn], dp[maxn][maxn][maxn];

void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

int main() {
  cin >> n >> m;
  rep(i, 1, n) {
    scanf("%1d", a + i), dp[a[i]][i][i] = 1;
  }
  sum[0] = sum[1] = 2;
  rep(num, 2, m) {
    sum[num] = 1ll * sum[num - 1] * sum[num - 2] % P;
    rep(l, 1, n) rep(r, l, n) {
      Add(dp[num][l][r], 1ll * dp[num - 1][l][r] * (r == n ? sum[num - 2] : 1) % P);
      Add(dp[num][l][r], 1ll * dp[num - 2][l][r] * (l == 1 ? sum[num - 1] : 1) % P);
      rep(k, l, r - 1) Add(dp[num][l][r], 1ll * dp[num - 1][l][k] * dp[num - 2][k + 1][r] % P);
    }
  }
  cout << dp[m][1][n];
  return 0;
}