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

typedef double db;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
const int maxn = 5e5 + 10;
int n, A[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int val[maxn << 2], tag[maxn << 2];

void maintain(int k) {
  val[k] = min(val[k << 1], val[k << 1 | 1]) + tag[k];
}

void build(int k, int l, int r) {
  tag[k] = val[k] = 0;
  if (l == r) return;
  build(lson), build(rson);
}

void upd(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    val[k] += x, tag[k] += x; return;
  }
  if (ql <= mid) upd(lson, ql, qr, x);
  if (qr > mid) upd(rson, ql, qr, x);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

int pl[maxn], pr[maxn], isl[maxn], isr[maxn], pos[maxn];

void solve() {
  cin >> n;
  int cnt0 = 0;
  rep(i, 1, n) A[i] = read(), cnt0 += !A[i];
  int mid = min(n / 3, cnt0 / 2), tmp = 0;
  if (!mid) return puts("0"), void();
  memset(isl, 0, (n + 1) << 2);
  memset(isr, 0, (n + 1) << 2);
  int cur = 0;
  rep(i, 1, n) if (!A[i]) {
    isl[i] = ++cur, pl[cur] = i;
    if (cur == mid) break;
  }
  cur = mid;
  per(i, n, 1) if (!A[i]) {
    pr[cur] = i, isr[i] = cur--;
    if (!cur) break;
  }
  memset(pos, 0, (n + 1) << 2);
  build(1, 1, mid);
  rep(i, 1, n) {
    if (A[i]) {
      int x = lower_bound(pl + 1, pl + mid + 1, pos[A[i]] + 1) - pl;
      int y = upper_bound(pl + 1, pl + mid + 1, i) - pl - 1;
      if (x <= y) upd(1, 1, mid, x, y, 1);
      pos[A[i]] = i;
    }
    if (isr[i]) {
      upd(1, 1, mid, 1, isr[i], -1);
      if (val[1] < 0) tmp++, upd(1, 1, mid, 1, isr[i], 1);
    }
  }
  printf("%d\n", mid - tmp);
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}