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
typedef unsigned long long ull;
int n;
char str[40];

int pre[40][20];
ull pw[20], dp[40][20];

void print(int i, int j) {
  if (i > 2 * n) return;
  putchar(pre[i][j] == j ? 'H' : 'M'), print(i + 1, pre[i][j]);
}

void solve() {
  scanf("%d %s", &n, str + 1);
  pw[0] = 1;
  rep(i, 1, n) pw[i] = 10 * pw[i - 1];
  per(i, 2 * n, 1) {
    int val = str[i] - '0';
    rep(j, 0, 2 * n - i + 1) {
      ull tmp1, tmp2;
      tmp1 = j ? dp[i + 1][j - 1] + val * pw[j - 1] : 0;
      tmp2 = j < 2 * n - i + 1 ? dp[i + 1][j] + val * pw[2 * n - i - j] : 0;
      if (j == 2 * n - i + 1 || (tmp1 > tmp2 && j)) {
        dp[i][j] = tmp1, pre[i][j] = j - 1;
      } else {
        dp[i][j] = tmp2, pre[i][j] = j;
      }
    }
  }
  print(1, n);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}