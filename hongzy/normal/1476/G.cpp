#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
const int N = 1e5 + 10;
int n, m, cntq, cntm, bel[N], a[N], ans[N];
struct node {
  int t, l, r, k;
  bool operator < (const node &b) const {
    return bel[l] != bel[b.l] ? l < b.l : (bel[r] != bel[b.r] ? r < b.r : t < b.t);
  }
} q[N];
struct mdf {
  int t, p, v;
} b[N];
 
int cnt[N], cc[N], L[N], R[N], hd = -1;
void add_c(int c) {
  if(c && !cc[c] ++) {
    L[c] = -1; R[c] = hd;
    if(~hd) L[hd] = c;
    hd = c;
  }
}
void del_c(int c) {
  if(c && !-- cc[c]) {
    int u = L[c], v = R[c];
    if(~u) R[u] = v;
    if(~v) L[v] = u;
    if(hd == c) hd = v;
  }
}
void add(int x) { del_c(cnt[x]); cnt[x] ++; add_c(cnt[x]); }
void del(int x) { del_c(cnt[x]); cnt[x] --; add_c(cnt[x]); }
int main() {
  scanf("%d%d", &n, &m);
  const int sz = max(1, int(pow(n, 2 / 3.0)));
  rep(i, 1, n) scanf("%d", a + i), bel[i] = (i - 1) / sz;
  rep(i, 1, m) {
    int op, l, r, k;
    scanf("%d%d%d", &op, &l, &r);
    if(op == 1) {
      scanf("%d", &k);
      q[++ cntq] = {i, l, r, k};
    }
    if(op == 2) {
      b[++ cntm] = {i, l, r};
      ans[i] = -1;
    }
  }
  sort(q + 1, q + cntq + 1);
  int t = 0, l = q[1].l, r = l - 1;
  rep(i, 1, cntq) {
    while(l > q[i].l) add(a[-- l]);
    while(r < q[i].r) add(a[++ r]);
    while(l < q[i].l) del(a[l ++]);
    while(r > q[i].r) del(a[r --]);
    while(t < cntm && b[t+1].t < q[i].t) {
      t ++;
      if(l <= b[t].p && b[t].p <= r) {
        del(a[b[t].p]); add(b[t].v);
      }
      swap(a[b[t].p], b[t].v);
    }
    while(b[t].t > q[i].t) {
      if(l <= b[t].p && b[t].p <= r) {
        del(a[b[t].p]); add(b[t].v);
      }
      swap(a[b[t].p], b[t].v);
      t --;
    }
    static int pos[N], sum[N];
    int cur = N, sz = 0;
    for(int u = hd; ~ u; u = R[u]) pos[++ sz] = u;
    sort(pos + 1, pos + sz + 1);
    sum[0] = 0;
    int p = 1;
    rep(j, 1, sz) {
      sum[j] = sum[j - 1] + cc[pos[j]];
      while(sum[j] - sum[p] >= q[i].k) p ++;
      if(sum[j] - sum[p - 1] >= q[i].k) {
        cur = min(cur, pos[j] - pos[p]);
      }
    }
    ans[q[i].t] = cur;
  }
  rep(i, 1, m) if(~ ans[i])
    printf("%d\n", ans[i] == N ? -1 : ans[i]);
  return 0;
}