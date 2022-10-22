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

struct LB {
  int bit[30];

  void clear() {
    memset(bit, 0, sizeof bit);
  }

  void ins(int x) {
    per(i, 29, 0) if (x >> i & 1) {
      if (bit[i]) {
        x ^= bit[i]; continue;
      }
      rep(j, 0, i - 1) if (x >> j & 1) x ^= bit[j];
      rep(j, i + 1, 29) if (bit[j] >> i & 1) bit[j] ^= x;
      bit[i] = x; return;
    }
  }
};

void merge(LB &res, LB A, LB B) {
  memcpy(res.bit, A.bit, sizeof A.bit);
  rep(i, 0, 29) if (B.bit[i]) res.ins(B.bit[i]);
}

int n, q, A[maxn];

int c[maxn];

void add(int pos, int x) {
  for (; pos <= n; pos += pos & -pos) {
    c[pos] ^= x;
  }
}

int query(int pos) {
  int res = 0;
  for (; pos; pos &= pos - 1) {
    res ^= c[pos];
  }
  return res;
}

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

LB qans, val[maxn << 2];

void build(int k, int l, int r) {
  if (l == r) return val[k].ins(A[l]), void();
  build(lson), build(rson), merge(val[k], val[k << 1], val[k << 1 | 1]);
}

void upd(int k, int l, int r, int x, int v) {
  if (l == r) return val[k].clear(), val[k].ins(v), void();
  x <= mid ? upd(lson, x, v) : upd(rson, x, v), merge(val[k], val[k << 1], val[k << 1 | 1]);
}

void query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return merge(qans, qans, val[k]), void();
  if (ql <= mid) query(lson, ql, qr);
  if (qr > mid) query(rson, ql, qr);
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin >> n >> q;
  rep(i, 1, n) A[i] = read();
  per(i, n, 1) add(i, A[i] ^= A[i - 1]);
  build(1, 1, n);
  while (q--) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      int x = read();
      add(l, x), add(r + 1, x);
//      memset(val, 0, sizeof val);
//      A[l] ^= x, A[r + 1] ^= x;
//      build(1, 1, n);
      upd(1, 1, n, l, A[l] ^= x);
      if (r < n) upd(1, 1, n, r + 1, A[r + 1] ^= x);
    } else {
      qans.clear();
      qans.ins(query(l));
      if (l < r) query(1, 1, n, l + 1, r);
      int res = 0;
      rep(i, 0, 29) if (qans.bit[i]) res++;
      printf("%d\n", 1 << res);
    }
  }
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}