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

void solve() {
  int x = read();
  if (!x) {
    puts("1 1"); return;
  }
  int tmp = sqrt(x) + 0.5;
  rep(i, 1, tmp) if (x % i == 0) {
    int a = (i + x / i), b = (x / i - i);
    if (a % 2 != 0 || b % 2 != 0 || b == 0) continue;
    a /= 2, b /= 2;
    int m = a / b;
    if (m > 0 && a / m == b) {
      printf("%d %d\n", a, m);
      return;
    }
    if (a / (m + 1) == b) {
      printf("%d %d\n", a, m + 1);
      return;
    }
  }
  puts("-1");
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}