#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

int n, k, a, b, q;

int val[N];
i64 sum[2 * N][2];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void add(int l, int r, int p, int v) {
  int id = pos(l, r);
  if (l == r) {
    val[p] += v;
    sum[id][0] = std::min(val[p], b);
    sum[id][1] = std::min(val[p], a);
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (p <= mid) add(l, mid, p, v); else add(mid + 1, r, p, v);
  sum[id][0] = sum[lch][0] + sum[rch][0];
  sum[id][1] = sum[lch][1] + sum[rch][1];
}

i64 query(int l, int r, int p, int q, int t) {
  int id = pos(l, r);
  if (p <= l && r <= q) return sum[id][t];
  int mid = (l + r) / 2;
  i64 res = 0;
  if (p <= mid) res += query(l, mid, p, q, t);
  if (q > mid) res += query(mid + 1, r, p, q, t);
  return res;
}

int main() {
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      add(1, n, x, y);
    } else {
      int p;
      scanf("%d", &p);
      i64 ans = 0;
      if (p > 1) ans += query(1, n, 1, p - 1, 0);
      if (p + k <= n) ans += query(1, n, p + k, n, 1);
      printf("%I64d\n", ans);
    }
  }
  return 0;
}