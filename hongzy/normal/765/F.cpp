#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int INF = 1.5e9;
struct node {
  int l, r, id;
} qs[M];
int n, m, a[N], b[N], num[N], ans[M];
struct fenwick {
  int bit[N];
  void clear() {
    rep(i, 1, n) bit[i] = INF;
  }
  void insert(int x, int y) {
    for(; x <= n; x += x & (-x))
      bit[x] = min(bit[x], y);
  }
  int query(int x) {
    int ans = INF;
    for(; x; x &= x - 1)
      ans = min(ans, bit[x]);
    return ans;
  }
} b0;
template<class T>
struct SMT {
  #define ls u << 1, l, mid
  #define rs u << 1 | 1, mid + 1, r
  T w[N * 4];
  void up(int u) {
    w[u] = min(w[u << 1], w[u << 1 | 1]);
  }
  void clear(int sz) {
    fill(w, w + (sz << 2) + 1, INF);
  }
  void modify(int u, int l, int r, int p, T v) {
    if(l == r) { w[u] = v; return ; }
    int mid = (l + r) >> 1;
    p <= mid ? modify(ls, p, v) : modify(rs, p, v);
    up(u);
  }
  T query(int u, int l, int r, int ql, int qr) {
    if(l == ql && r == qr) return w[u];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ls, ql, qr);
    if(ql > mid) return query(rs, ql, qr);
    return min(query(ls, ql, mid), query(rs, mid + 1, qr));
  }
};
SMT<int> seg;
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), num[i] = a[i];
  sort(num + 1, num + n + 1);
  rep(i, 1, n) b[i] = lower_bound(num + 1, num + n + 1, a[i]) - num;
  scanf("%d", &m);
  rep(i, 1, m) {
    scanf("%d%d", &qs[i].l, &qs[i].r);
    qs[i].id = i;
  }
  sort(qs + 1, qs + m + 1, [&](node x, node y) {
    return x.l < y.l;
  });
  int p = m;
  b0.clear(); seg.clear(n);
  seg.modify(1, 1, n, b[n], n);
  per(i, n - 1, 1) {
    int z = seg.query(1, 1, n, b[i], n);
    if(z <= n) {
      b0.insert(z, a[z] - a[i]);
      while(1) {
        if(a[z] == a[i]) break ;
        int lim = (a[z] + a[i]) >> 1;
        lim = upper_bound(num + 1, num + n + 1, lim) - num - 1;
        int y = seg.query(1, 1, n, b[i], lim);
        if(y > n) break ;
        b0.insert(y, a[y] - a[i]);
        z = y;
      }
    }
    z = seg.query(1, 1, n, 1, b[i]);
    if(z <= n) {
      b0.insert(z, a[i] - a[z]);
      while(1) {
        if(a[i] == a[z]) break ;
        int lim = (a[z] + a[i] + 1) >> 1;
        lim = lower_bound(num + 1, num + n + 1, lim) - num;
        int y = seg.query(1, 1, n, lim, b[i]);
        if(y > n) break ;
        b0.insert(y, a[i] - a[y]);
        z = y;
      }
    }
    while(p && qs[p].l == i) {
      ans[qs[p].id] = b0.query(qs[p].r);
      p --;
    }
    seg.modify(1, 1, n, b[i], i);
  }
  rep(i, 1, m)
    printf("%d\n", ans[i]);
  return 0;
}