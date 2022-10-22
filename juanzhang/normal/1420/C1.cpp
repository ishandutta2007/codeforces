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
const int maxn = 3e5 + 10;
int n, q, A[maxn], chk[maxn];

void solve() {
  cin >> n >> q;
  rep(i, 1, n) {
    A[i] = read();
  }
  A[n + 1] = 0;
  ll ans = 0, sum = 0, cur = 1;
  rep(i, 1, n) {
    chk[i] = 0;
    if (A[i - 1] < A[i] && A[i] > A[i + 1]) chk[i] = 1;
    if (A[i - 1] > A[i] && A[i] < A[i + 1]) chk[i] = -1;
    if (cur == chk[i]) {
      ans = sum, sum += cur * A[i], cur = -cur;
    }
  }
  chkmax(ans, sum);
  cout << ans << endl;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}