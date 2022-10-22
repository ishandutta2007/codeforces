#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, bsz, qtot, utot, a[maxn], lst[maxn], bl[maxn], ans[maxn], c[maxn << 1], cnt[maxn << 1];

struct Update {
  int pos, pre, nxt;
} U[maxn];

struct Query {
  int l, r, t, tid;
  bool operator < (const Query& o) const {
    return bl[l] == bl[o.l] ? bl[r] == bl[o.r] ? t < o.t : r < o.r : l < o.l;
  }
} Q[maxn];

void discretion() {
  #define get_val(x) (lower_bound(data + 1, data + tot + 1, x) - data)
  static int tot, data[maxn << 1];
  for (int i = 1; i <= n; i++) {
    data[i] = a[i];
  }
  for (int i = 1; i <= utot; i++) {
    data[n + i] = U[i].nxt;
  }
  tot = n + utot;
  sort(data + 1, data + tot + 1);
  tot = unique(data + 1, data + tot + 1) - data - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = get_val(a[i]);
  }
  for (int i = 1; i <= utot; i++) {
    U[i].pre = get_val(U[i].pre);
    U[i].nxt = get_val(U[i].nxt);
  }
}

void upd(int x, int v) {
  cnt[c[x]]--, cnt[c[x] += v]++;
}

void update(int t, int l, int r, int op) {
  int p = U[t].pos, x = op ? U[t].pre : U[t].nxt;
  if (l <= p && p <= r) {
    upd(a[p], -1), upd(x, 1);
  }
  a[p] = x;
}

int main() {
  scanf("%d %d", &n, &m);
  bsz = pow(n, 0.666666);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    lst[i] = a[i];
    bl[i] = (i - 1) / bsz + 1;
  }
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1) {
      Q[++qtot] = Query{x, y, utot, qtot};
    } else {
      U[++utot] = Update{x, lst[x], y}, lst[x] = y;
    }
  }
  discretion();
  cnt[0] = n << 1;
  int l = 1, r = 0, now = 0;
  sort(Q + 1, Q + qtot + 1);
  for (int i = 1; i <= qtot; i++) {
    while (l > Q[i].l) upd(a[--l], 1);
    while (r < Q[i].r) upd(a[++r], 1);
    while (l < Q[i].l) upd(a[l++], -1);
    while (r > Q[i].r) upd(a[r--], -1);
    while (now < Q[i].t) update(++now, l, r, 0);
    while (now > Q[i].t) update(now--, l, r, 1);
    while (cnt[ans[Q[i].tid]]) ans[Q[i].tid]++;
  }
  for (int i = 1; i <= qtot; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}