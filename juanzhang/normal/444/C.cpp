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
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1e5 + 10;
int n, q;

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

ll sum[maxn << 2], tag[maxn << 2];
int len[maxn << 2], col[maxn << 2];

void maintain(int k) {
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
  col[k] = col[k << 1] == col[k << 1 | 1] ? col[k << 1] : 0;
}

void pushtag(int k, ll x) {
  sum[k] += x * len[k], tag[k] += x;
}

void pushdown(int k) {
  ll &x = tag[k];
  if (x) pushtag(k << 1, x), pushtag(k << 1 | 1, x), x = 0;
  if (col[k]) col[k << 1] = col[k << 1 | 1] = col[k];
}

void build(int k, int l, int r) {
  len[k] = r - l + 1;
  if (l == r) {
    col[k] = l; return;
  }
  build(lson), build(rson), maintain(k);
}

void upd(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr && col[k]) {
    pushtag(k, abs(col[k] - x)), col[k] = x; return;
  }
  pushdown(k);
  if (ql <= mid) upd(lson, ql, qr, x);
  if (qr > mid) upd(rson, ql, qr, x);
  maintain(k);
}

ll query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[k];
  pushdown(k); ll res = 0;
  if (ql <= mid) res = query(lson, ql, qr);
  if (qr > mid) res += query(rson, ql, qr);
  return res;
}

#undef mid
#undef lson
#undef rson

int main() {
  cin >> n >> q;
  build(1, 1, n);
  while (q--) {
    int op = read(), l = read(), r = read();
    if (op == 1) {
      int x = read();
      upd(1, 1, n, l, r, x);
    } else {
      printf("%I64d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}