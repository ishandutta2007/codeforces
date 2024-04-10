#include <bits/stdc++.h>
using namespace std;

const int maxn = 35010;
int n, k, now, a[maxn], pos[maxn], lst[maxn], f[55][maxn];

#define mid ((l + r) >> 1)
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r

int val[maxn << 2], tag[maxn << 2];

void pushtag(int k, int x) {
  tag[k] += x, val[k] += x;
}

void pushdown(int k) {
  if (tag[k]) {
    pushtag(k << 1, tag[k]);
    pushtag(k << 1 | 1, tag[k]);
    tag[k] = 0;
  }
}

void maintain(int k) {
  val[k] = max(val[k << 1], val[k << 1 | 1]);
}

void build(int k, int l, int r) {
  tag[k] = 0;
  if (l == r) {
    val[k] = f[now - 1][l - 1]; return;
  }
  build(lson), build(rson);
  maintain(k);
}

void upd(int k, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    pushtag(k, 1); return;
  }
  pushdown(k);
  if (ql <= mid) upd(lson, ql, qr);
  if (qr > mid) upd(rson, ql, qr);
  maintain(k);
}

int query(int k, int l, int r, int x) {
  if (r <= x) return val[k];
  pushdown(k);
  if (x > mid) {
    return max(val[k << 1], query(rson, x));
  } else {
    return query(lson, x);
  }
}

#undef mid
#undef lson
#undef rson

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    lst[i] = pos[a[i]], pos[a[i]] = i;
  }
  for (now = 1; now <= k; now++) {
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      upd(1, 1, n, lst[i] + 1, i);
      f[now][i] = query(1, 1, n, i);
    }
  }
  printf("%d", f[k][n]);
  return 0;
}