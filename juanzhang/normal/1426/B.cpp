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
typedef pair <int, int> pii;
int n, m;

void solve() {
  cin >> n >> m;
  bool t = 0, t1 = 0, t2 = 0;
  rep(i, 1, n) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool f1 = a == d;
    bool f2 = b == c;
    t |= f1 && f2, t1 |= f1, t2 |= f2;
  }
  if (m % 2 == 1) {
    puts("NO");
  } else {
    puts(t2 ? "YES" : "NO");
  }
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}