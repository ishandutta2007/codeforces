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
const int maxn = 1e5 + 10;
int n, A[maxn];

void solve() {
  static int cnt[40];
  memset(cnt, 0, sizeof cnt);
  cin >> n;
  rep(i, 1, n) {
    int x = read();
    per(j, 29, -1) {
      if (j == -1 || (x >> j & 1)) {
        cnt[j + 1]++; break;
      }
    }
  }
  ll res = 0;
  rep(i, 0, 30) res += 1ll * cnt[i] * (cnt[i] - 1) / 2;
  cout << res << endl;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}