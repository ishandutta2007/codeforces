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
  ll a = read(),b = read(), n=read();
  int cur = 0;
  while (1) {
    cur++;
    if (a < b) swap(a, b);
    b += a;
    if (b > n) {
      printf("%d\n", cur); return;
    }
  }
}

int main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}