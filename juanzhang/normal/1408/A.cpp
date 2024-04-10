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
int n, A[3][101], p[101];

void solve() {
  cin >> n;
  rep(i, 0, 2) rep(j, 1, n) A[i][j] = read();
  p[1] = A[0][1];
  rep(i, 2, n) {
    rep(j, 0, 2) {
      if (A[j][i] != p[i - 1] && (i < n || A[j][i] != p[1])) {
        p[i] = A[j][i]; break;
      }
    }
  }
  rep(i, 1, n) printf("%d%c", p[i], "\n "[i < n]);
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}