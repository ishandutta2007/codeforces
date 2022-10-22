#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 2e5 + 10;
int n, m;

struct Querys {
  int c; ll l;
} ans[maxn];

struct node {
  ll x, y; int tid;
  
  inline bool operator < (const node &o) const {
    return x < o.x;
  }
} a[maxn];

int tot;
ll lst[maxn];

namespace A {
  // Another Useless Segment Tree
  
  #define mid ((l + r) >> 1)
  #define lson k << 1, l, mid
  #define rson k << 1 | 1, mid + 1, r
  
  ll tag[maxn << 2], val[maxn << 2];
  
  void maintain(int k) {
    val[k] = max(val[k << 1], val[k << 1 | 1]);
  }
  
  void pushtag(int k, ll x) {
    tag[k] = x, val[k] = x;
  }
  
  void pushdown(int k) {
    if (~tag[k]) {
      pushtag(k << 1, tag[k]);
      pushtag(k << 1 | 1, tag[k]);
      tag[k] = -1;
    }
  }
  
  void build(int k, int l, int r) {
    tag[k] = -1;
    if (l == r) {
      val[k] = a[l].y; return;
    }
    build(lson), build(rson);
    maintain(k);
  }
  
  void upd(int k, int l, int r, int ql, int qr, ll x) {
    if (ql <= l && r <= qr) {
      pushtag(k, x); return;
    }
    pushdown(k);
    if (ql <= mid) upd(lson, ql, qr, x);
    if (qr > mid) upd(rson, ql, qr, x);
    maintain(k);
  }
  
  int query(int k, int l, int r, int ql, int qr, ll x) {
    if (l < r) pushdown(k);
    if (val[k] <= x) return 0;
    if (l == r) {
      return l;
    }
    int res = 0;
    if (ql <= mid) res = query(lson, ql, qr, x);
    if (qr > mid && !res) res = query(rson, ql, qr, x);
    return res;
  }
  
  #undef mid
  #undef lson
  #undef rson
}

void build() {
  ll mx = 0;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i].y > mx) {
      mx = a[i].y;
      a[++tot] = a[i];
    }
  }
  A::build(1, 1, tot);
}

void add(int pos, ll v, int addcnt) {
  a[pos].y += v;
  ans[a[pos].tid].l += v;
  ans[a[pos].tid].c += addcnt;
  int t = tot + 1;
  if (pos < tot) t = A::query(1, 1, tot, pos + 1, tot, a[pos].y);
  A::upd(1, 1, tot, pos, !t ? tot : t - 1, a[pos].y);
}

#define mid ((l + r) >> 1)
#define lson ls[k], l, mid
#define rson rs[k], mid + 1, r

int cnt = 1, addcnt;
ll addsum, addv[maxn * 30];
int ls[maxn * 30], rs[maxn * 30], sz[maxn * 30];

void maintain(int k) {
  sz[k] = sz[ls[k]] + sz[rs[k]];
}

void ins(int k, int l, int r, int pos, int v) {
  if (l == r) {
    sz[k]++, addv[k] += v; return;
  }
  if (pos <= mid) {
    if (!ls[k]) ls[k] = ++cnt;
    ins(lson, pos, v);
  } else {
    if (!rs[k]) rs[k] = ++cnt;
    ins(rson, pos, v);
  }
  maintain(k);
}

void query(int k, int l, int r, int ql, int qr) {
  if (!sz[k]) return;
  if (l == r) {
    addsum += addv[k], addcnt += sz[k], addv[k] = sz[k] = 0;
    return;
  }
  if (ls[k] && ql <= mid) query(lson, ql, qr);
  if (rs[k] && qr > mid) query(rson, ql, qr);
  maintain(k);
}

#undef mid
#undef lson
#undef rson

void upd(int x, int v) {
  int pos = A::query(1, 1, tot, 1, tot, x - 1);
  if (!pos || a[pos].x > x) {
    ins(1, 0, 1e9, x, v); return;
  }
  ll tmp = a[pos].y + 1;
  add(pos, v, 1);
  while (1) {
    addsum = addcnt = 0;
    ll l = tmp, r = a[pos].y;
    if (l > r || l > 1e9) break;
    if (r > 1e9) r = 1e9;
    query(1, 0, 1e9, l, r);
    if (!addcnt) break;
    tmp = a[pos].y + 1;
    add(pos, addsum, addcnt);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i].x, &a[i].y);
    ans[i] = Querys{0, a[i].y};
    a[i].y += a[i].x, a[i].tid = i;
  }
  build();
  while (m--) {
    int x, v;
    scanf("%d %d", &x, &v);
    upd(x, v);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d %I64d\n", ans[i].c, ans[i].l);
  }
  return 0;
}