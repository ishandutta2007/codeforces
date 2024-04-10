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
const int maxn = 5010;
int n, A[maxn];

int divide(int l, int r) {
  if (l > r) return 1e9;
  if (l == r) return min(A[l], 1);
  int pos = -1;
  rep(i, l, r) if (pos == -1 || A[pos] > A[i]) {
    pos = i;
  }
  ll res = A[pos]; int cur = l;
  rep(i, l, r) A[i] -= res;
  rep(i, l, r) {
    if (!A[i]) {
      cur = i + 1;
    } else if (i == r || !A[i + 1]) {
      res += divide(cur, i);
    }
  }
  return min(res, (ll) r - l + 1);
}

void solve() {
  cin >> n;
  rep(i, 1, n) A[i] = read();
  cout << divide(1, n) << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}