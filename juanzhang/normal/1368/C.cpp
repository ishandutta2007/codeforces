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

void solve() {
  int n;
  cin >> n;
  int cnt = 3 * (n + 1) + 1;
  printf("%d\n", cnt);
  puts("0 0\n0 1\n1 0");
  int x = 1, y = 1;
  rep(i, 1, n) {
    printf("%d %d\n%d %d\n%d %d\n", x, y, x + 1, y, x, y + 1);
    x++, y++;
  }
  printf("%d %d\n", x, y);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}