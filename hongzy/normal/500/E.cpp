#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
struct discrete {
  vector<int> v;
  vector<int>::iterator ep;
  int operator [](int x) { return v[x - 1]; }
  void push(int x) { v.pb(x); }
  int size() { return ep - v.begin(); }
  void build() { sort(v.begin(), v.end()); ep = unique(v.begin(), v.end()); }
  int get(int x) { return lower_bound(v.begin(), ep, x) - v.begin() + 1; }
} ds;
struct node { int l, r, id; } a[N], b[N];
int n, q, sum[N * 8], w[N * 8], ans[N];
bool tag[N * 8];
void build(int u, int l, int r) {
  if(l < r) {
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
  }
  sum[u] = ds[r + 1] - ds[l];
}
void upd(int u) {
  w[u] = w[u * 2] + w[u * 2 + 1];
}
void pd(int u) {
  if(tag[u]) {
    tag[u * 2] = tag[u * 2 + 1] = 1;
    w[u * 2] = sum[u * 2];
    w[u * 2 + 1] = sum[u * 2 + 1];
    tag[u] = 0;
  }
}
void cover(int u, int l, int r, int ql, int qr) {
  if(l == ql && r == qr) {
    tag[u] = 1; w[u] = sum[u]; return ;
  }
  pd(u);
  int mid = (l + r) / 2;
  if(qr <= mid) {
    cover(u * 2, l, mid, ql, qr);
  } else if(ql > mid) {
    cover(u * 2 + 1, mid + 1, r, ql, qr);
  } else {
    cover(u * 2, l, mid, ql, mid);
    cover(u * 2 + 1, mid + 1, r, mid + 1, qr);
  }
  upd(u);
}
int query(int u, int l, int r, int ql, int qr) {
  if(l == ql && r == qr) {
    return w[u];
  }
  pd(u);
  int mid = (l + r) / 2;
  if(qr <= mid) {
    return query(u * 2, l, mid, ql, qr);
  }
  if(ql > mid) {
    return query(u * 2 + 1, mid + 1, r, ql, qr);
  }
  return query(u * 2, l, mid, ql, mid) + query(u * 2 + 1, mid + 1, r, mid + 1, qr);
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d%d", &a[i].l, &a[i].r); a[i].r += a[i].l;
    ds.push(a[i].l); ds.push(a[i].r);
  }
  ds.build();
  rep(i, 1, n) {
    a[i].l = ds.get(a[i].l);
    a[i].r = ds.get(a[i].r);
  }
  build(1, 1, ds.size() - 1);
  scanf("%d", &q);
  rep(i, 1, q) {
    scanf("%d%d", &b[i].l, &b[i].r);
    b[i].id = i;
  }
  sort(b + 1, b + q + 1, [&](node x, node y) { return x.l > y.l; });
  int p = n + 1;
  rep(i, 1, q) {
    while(p - 1 >= b[i].l) {
      p --;
      cover(1, 1, ds.size() - 1, a[p].l, a[p].r - 1);
    }
    ans[b[i].id] = ds[a[b[i].r].l] - ds[a[b[i].l].l] - query(1, 1, ds.size() - 1, a[b[i].l].l, a[b[i].r].l - 1);
  }
  // printf("w[%d] = %d\n", 1, w[1]);
  rep(i, 1, q) {
    printf("%d\n", ans[i]);
  }
  return 0;
}