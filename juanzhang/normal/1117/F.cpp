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

const int maxn = 1e5 + 10;
char str[maxn];
int n, m, lst[17], G[17][17], sum[17][maxn];

bitset <(1 << 17)> dp, vis, mark[17][17];

int main() {
  scanf("%d %d %s", &n, &m, str + 1);
  rep(i, 0, m - 1) rep(j, 0, m - 1) {
    G[i][j] = read();
  }
  int all = (1 << m) - 1;
  rep(i, 1, n) {
    int x = str[i] - 'a';
    rep(j, 0, m - 1) {
      sum[j][i] = sum[j][i - 1] + (x == j);
      if (G[x][j] || !lst[j]) continue;
      int S = all;
      rep(k, 0, m - 1) {
        if (k != x && k != j && sum[k][i - 1] - sum[k][lst[j]]) {
          S ^= 1 << k;
        }
      }
      mark[min(x, j)][max(x, j)][S] = 1;
    }
    lst[x] = i;
  }
  rep(p, 0, m - 1) rep(q, p, m - 1) if (!G[p][q]) {
    per(S, all, 0) if (mark[p][q][S]) {
      vis[S] = 1;
      rep(i, 0, m - 1) if (i != p && i != q && S >> i & 1) {
        mark[p][q][S ^ 1 << i] = 1;
      }
    }
  }
  int res = n;
  dp[all] = 1;
  per(S, all, 0) {
    if (dp[S]) {
      int val = 0;
      rep(i, 0, m - 1) if (S >> i & 1) {
        val += sum[i][n], dp[S ^ 1 << i] = !vis[S ^ 1 << i];
      }
      chkmin(res, val);
    }
  } 
  cout << res;
  return 0;
}