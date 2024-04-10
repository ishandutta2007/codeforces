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

const int maxn = 2e5 + 10;
int n, m, k;

struct node {
  int x, val;
} A[maxn], B[maxn];

int pos[maxn];

struct point {
  int x, y, val;
} data[maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int tag[maxn << 2], val[maxn << 2];

void maintain(int k) {
  val[k] = max(val[k << 1], val[k << 1 | 1]);
}

void pushtag(int k, int x) {
  tag[k] += x, val[k] += x;
}

void pushdown(int k) {
  int &x = tag[k];
  if (x) {
    pushtag(k << 1, x), pushtag(k << 1 | 1, x), x = 0;
  }
}

void build(int k, int l, int r) {
  if (l == r) {
    pos[l] = B[l].x, val[k] = -B[l].val;
    return;
  }
  build(lson), build(rson);
  maintain(k);
}

void upd(int k, int l, int r, int pos, int x) {
  if (pos > r) return;
  if (pos <= l) {
    pushtag(k, x); return;
  }
  pushdown(k);
  if (pos <= mid) {
    upd(lson, pos, x), pushtag(k << 1 | 1, x);
  } else {
    upd(rson, pos, x);
  }
  maintain(k);
}

#undef mid
#undef lson
#undef rson

signed main() {
  cin >> n >> m >> k;
  rep(i, 1, n) {
    A[i].x = read(), A[i].val = read();
  }
  rep(i, 1, m) {
    B[i].x = read(), B[i].val = read();
  }
  rep(i, 1, k) {
    data[i].x = read(), data[i].y = read(), data[i].val = read();
  }
  sort(A + 1, A + n + 1, [] (node P, node Q) {
    return P.x < Q.x;
  });
  sort(B + 1, B + m + 1, [] (node P, node Q) {
    return P.x < Q.x;
  });
  sort(data + 1, data + k + 1, [] (point P, point Q) {
    return P.x < Q.x;
  });
  int res = -2.1e9;
  build(1, 1, m);
  for (int i = 1, j = 1; i <= n; i++) {
    for (; j <= k && data[j].x < A[i].x; j++) {
      int tmp = upper_bound(pos + 1, pos + m + 1, data[j].y) - pos;
      if (tmp <= m) upd(1, 1, m, tmp, data[j].val);
    }
    chkmax(res, val[1] - A[i].val);
  }
  cout << res;
  return 0;
}