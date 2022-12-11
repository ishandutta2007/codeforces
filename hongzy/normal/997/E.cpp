#include <bits/stdc++.h>
#define pb push_back
#define ls u << 1
#define rs u << 1 | 1
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n, q, a[N], st1[N], st2[N], top1, top2;
ll ans[N];
struct Query { int l, id; };
vector<Query> v[N];
struct node { int l, r, minv, lz1, lz2; ll num, sum; } t[N << 2];
void upd(int u) {
  t[u].minv = min(t[ls].minv, t[rs].minv);
  t[u].num = 0;
  if(t[ls].minv == t[u].minv) t[u].num += t[ls].num;
  if(t[rs].minv == t[u].minv) t[u].num += t[rs].num;
  t[u].sum = t[ls].sum + t[rs].sum;
}
void build(int u, int l, int r) {
  t[u].l = l; t[u].r = r;
  if(l == r) { t[u].minv = l; t[u].num = 1; return; }
  int mid = (l + r) >> 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
  upd(u);
}
void mktag1(int u, ll v) { t[u].minv += v; t[u].lz1 += v; }
void mktag2(int u, ll v) { t[u].sum += t[u].num * v; t[u].lz2 += v; }
void pd(int u) {
  if(t[u].lz1) {
    mktag1(ls, t[u].lz1);
    mktag1(rs, t[u].lz1);
    t[u].lz1 = 0;
  }
  if(t[u].lz2) {
    if(t[ls].minv == t[u].minv) mktag2(ls, t[u].lz2);
    if(t[rs].minv == t[u].minv) mktag2(rs, t[u].lz2);
    t[u].lz2 = 0;
  }
}
void add(int u, int l, int r, ll v) {
  if(t[u].l == l && t[u].r == r) { mktag1(u, v); return; }
  pd(u);
  int mid = (t[u].l + t[u].r) >> 1;
  if(r <= mid) add(ls, l, r, v);
  else if(l > mid) add(rs, l, r, v);
  else {
    add(ls, l, mid, v);
    add(rs, mid + 1, r, v);
  }
  upd(u);
}
ll query(int u, int l, int r) {
  if(t[u].l == l && t[u].r == r) return t[u].sum;
  pd(u);
  int mid = (t[u].l + t[u].r) >> 1;
  if(r <= mid) return query(ls, l, r);
  if(l > mid) return query(rs, l, r);
  return query(ls, l, mid) + query(rs, mid + 1, r);
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++) scanf("%d", a + i);
  scanf("%d", &q);
  for(int i = 1; i <= q; i ++) { int l, r; scanf("%d%d", &l, &r); v[r].pb({l, i}); }
  build(1, 1, n);
  for(int i = 1; i <= n; i ++) {
    while(top1 && a[st1[top1]] < a[i])
      add(1, st1[top1 - 1] + 1, st1[top1], a[i] - a[st1[top1]]), top1 --;
    while(top2 && a[st2[top2]] > a[i])
      add(1, st2[top2 - 1] + 1, st2[top2], a[st2[top2]] - a[i]), top2 --;
    st1[++ top1] = st2[++ top2] = i;
    mktag1(1, -1);
    mktag2(1, 1);
    for(auto x : v[i]) {
      ans[x.id] = query(1, x.l, i);
    }
  }
  for(int i = 1; i <= q; i ++) printf("%lld\n", ans[i]);
  return 0;
}