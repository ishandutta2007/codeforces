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
const int maxn = 2e5 + 10;
int n, A[maxn];

int cnt[20];

void solve() {
  cin >> n;
  rep(i, 1, n) {
    A[i] = read();
    rep(j, 0, 19) cnt[j] += A[i] >> j & 1;
  }
  ll res = 0;
  rep(i, 1, n) {
    int x = 0;
    rep(j, 0, 19) x += i <= cnt[j] ? 1 << j : 0;
    res += 1ll * x * x;
  }
  cout << res << endl;
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}