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
typedef long double db;
typedef pair <int, int> pii;
const db eps = 1e-7;
const int maxn = 1e5 + 10;
int n, L, A[maxn], B[maxn];

db get(int *A, db mid) {
  int cur = 0, sp = 1;
  rep(i, 1, n + 1) {
    db ti = (db) (A[i] - cur) / sp;
    if (ti > mid) {
      return cur + sp * mid;
    }
    mid -= ti;
    cur = A[i], sp++;
  }
  return cur;
}

bool pd(db mid) {
  db x = get(A, mid);
  db y = L - get(B, mid);
  return x < y;
}

void solve() {
  cin >> n >> L;
  rep(i, 1, n) A[i] = read();
  A[n + 1] = L;
  rep(i, 1, n + 1) B[i] = L - A[n - i + 1];
  db l = 0, r = 1e9;
  while (r - l > eps) {
    db mid = (l + r) / 2;
    pd(mid) ? l = mid : r = mid;
  }
  printf("%.10lf\n", (double) l);
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}