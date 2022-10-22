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
int n, q, A[maxn], chk[maxn], val[maxn];

bool pd1(int x) {
  return A[x - 1] < A[x] && A[x] > A[x + 1];
}

bool pd2(int x) {
  return A[x - 1] > A[x] && A[x] < A[x + 1];
}

void solve() {
  cin >> n >> q;
  rep(i, 1, n) A[i] = read();
  A[n + 1] = 0;
  ll ans = 0;
  rep(i, 1, n) {
    chk[i] = 0;
    if (pd1(i)) chk[i] = 1;
    if (pd2(i)) chk[i] = -1;
    ans += val[i] = A[i] * chk[i];
  }
  cout << ans << endl;
  while (q--) {
    int x = read(), y = read();
    swap(A[x], A[y]);
    rep(t, -1, 1) {
      int i = x + t;
      rep(j, 0, 1) {
        if (i >= 1 && i <= n) {
          ans -= val[i];
          chk[i] = 0;
          if (pd1(i)) chk[i] = 1;
          if (pd2(i)) chk[i] = -1;
          ans += val[i] = A[i] * chk[i];
        }
        i = y + t;
      }
    }
    printf("%lld\n", ans);
  }
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}