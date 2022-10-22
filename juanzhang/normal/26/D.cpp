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
typedef long double db;

int n, m, k;

void solve() {
  cin >> n >> m >> k;
  if (k + n - m < 0) {
    puts("0"); return;
  }
  if (k - m >= 0) {
    puts("1"); return;
  }
  db res = 1;
  rep(i, 0, k) {
    res *= (db) (m - i) / (n + i + 1);
  }
  printf("%.10lf", double (1 - res));
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}