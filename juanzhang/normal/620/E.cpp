#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 4e5 + 10;
int n, m, a[maxn], data[maxn];

vector <int> e[maxn];
int sz[maxn], tid[maxn];

int dfs(int u, int f) {
  static int now;
  tid[u] = ++now;
  data[now] = a[u];
  for (int v : e[u]) {
    if (v != f) {
      sz[u] += dfs(v, u);
    }
  }
  return ++sz[u];
}

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

ll val[maxn << 2];
int tag[maxn << 2];

void maintain(int k) {
  val[k] = val[k << 1] | val[k << 1 | 1];
}

void pushtag(int k, int x) {
  if (x) tag[k] = x, val[k] = 1ll << x;
}

void pushdown(int k) {
  pushtag(k << 1, tag[k]);
  pushtag(k << 1 | 1, tag[k]);
  tag[k] = 0;
}

void build(int k, int l, int r) {
  if (l == r) {
    val[k] = 1ll << data[l];
    return;
  }
  build(lson), build(rson);
  maintain(k);
}

void upd(int k, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    pushtag(k, x); return;
  }
  pushdown(k);
  if (ql <= mid) upd(lson, ql, qr, x);
  if (qr > mid) upd(rson, ql, qr, x);
  maintain(k);
}

ll query(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    return val[k];
  }
  pushdown(k); ll res = 0;
  if (ql <= mid) res = query(lson, ql, qr);
  if (qr > mid) res |= query(rson, ql, qr);
  return res;
}

#undef mid
#undef lson
#undef rson

int main() {
  scanf("%d %d", &n, &m);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, n - 1) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs(1, 0);
  build(1, 1, n);
  while (m--) {
    int op, u;
    scanf("%d %d", &op, &u);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      upd(1, 1, n, tid[u], tid[u] + sz[u] - 1, x);
    } else {
      printf("%d\n", __builtin_popcountll(query(1, 1, n, tid[u], tid[u] + sz[u] - 1)));
    }
  }
  return 0;
}