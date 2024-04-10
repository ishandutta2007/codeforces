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
int n, q, A[maxn], ans[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int tag[maxn << 2];
pii val[maxn << 2];

void pushtag(int k, int x) {
  tag[k] += x, val[k].first += x;
}

void pushdown(int k) {
  int &x = tag[k];
  if (!x) return;
  pushtag(k << 1, x), pushtag(k << 1 | 1, x), x = 0;
}

void maintain(int k) {
  val[k] = max(val[k << 1], val[k << 1 | 1]);
}

void build(int k, int l, int r) {
  if (l == r) return val[k] = {A[l], l}, void();
  build(lson), build(rson), maintain(k);
}

void upd(int k, int l, int r, int x, int v) {
  if (l == r) return val[k] = {v, x}, void();
  pushdown(k);
  x <= mid ? upd(lson, x, v) : upd(rson, x, v); maintain(k);
}

void add(int k, int l, int r, int ql) {
  if (ql <= l) return pushtag(k, 1), void();
  pushdown(k);
  if (ql <= mid) add(lson, ql);
  add(rson, ql);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

int init[maxn];
bool used[maxn];

struct Querys {
  int l, r, tid;
} Q[maxn];

int c[maxn];

void add(int pos, int x) {
  for (; pos; pos &= pos - 1) c[pos] += x;
}

int query(int pos) {
  int res = 0;
  for (; pos <= n; pos += pos & -pos) res += c[pos];
  return res;
}

void solve() {
  int tmpq;
  cin >> n >> tmpq;
  rep(i, 1, n) A[i] = read() - i;
  rep(i, 1, tmpq) {
    int x = read() + 1, y = n - read();
    if (x <= y) q++, Q[q] = {x, y, q};
  }
  sort(Q + 1, Q + q + 1, [] (Querys P, Querys Q) {
    return P.l > Q.l;
  });
  build(1, 1, n);
  int now = n + 1, cur = 1;
  for (int T = 0; ; ) {
    pii p = val[1];
    if (p.first < 0) break;
    upd(1, 1, n, p.second, -1e9);
    if (p.first == 0) {
      used[p.second] = 1, add(1, 1, n, p.second);
      add(p.second, 1);
      if (now > p.second) {
        per(i, now, p.second + 1) {
          for (; cur <= q && Q[cur].l == i; cur++) {
            ans[Q[cur].tid] = -query(Q[cur].r + 1);
          }
        }
        now = p.second;
      }
      init[now] = ++T;
//      printf("(%d %d)\n" ,p.second,T);
    }
  }
  for (; cur <= q; cur++) ans[Q[cur].tid] = -query(Q[cur].r + 1);
  per(i, n, 1) chkmax(init[i], init[i + 1]);
//  rep(i, 1, n) printf("%d%c", used[i], "\n "[i < n]);
//  rep(i, 1, n) printf("%d%c", init[i], "\n "[i < n]);
  rep(i, 1, q) if (Q[i].l <= Q[i].r) ans[Q[i].tid] += init[Q[i].l];
  rep(i, 1, q) printf("%d\n", ans[i]);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}