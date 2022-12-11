#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10;
const int M = N * 400;
int n, m, l[N], r[N], ans[N];
vector<int> vec[N];
int id, a[M], ls[M], rs[M], rt[N];
void ins(int &u, int l, int r, int x, int w) {
  if(!u) { u = ++ id; a[u] = N; }
  a[u] = min(a[u], w);
  if(l == r) return ;
  int mid = (l + r) >> 1;
  if(x <= mid) ins(ls[u], l, mid, x, w);
  else ins(rs[u], mid + 1, r, x, w);
}
int qry(int u, int l, int r, int ql, int qr) {
  if(!u) return N;
  if(l == ql && r == qr) return a[u];
  int mid = (l + r) >> 1;
  if(qr <= mid) return qry(ls[u], l, mid, ql, qr);
  if(ql > mid) return qry(rs[u], mid + 1, r, ql, qr);
  return min(qry(ls[u], l, mid, ql, mid), qry(rs[u], mid + 1, r, mid + 1, qr));
}
void insert(int x, int y, int w) {
  for(; x; x &= x - 1)
    ins(rt[x], 1, n, y, w);
}
int query(int x, int y) {
  int z = N;
  for(; x <= n; x += x & (-x))
    z = min(z, qry(rt[x], 1, n, 1, y));
  return z;
}
int cur;
void solve(int l, int r) {
  if(l > r) return ;
  int id = query(l, r);
  if(id > m) return ;
  cur += ::r[id] - ::l[id] + 1;
  solve(l, ::l[id] - 1);
  solve(::r[id] + 1, r);
}
int main() {
  scanf("%d%d", &n, &m);
  int x, y;
  rep(i, 1, m) {
    scanf("%d%d", &x, &y);
    l[i] = x; r[i] = y;
    vec[y - x + 1].push_back(i);
  }
  per(i, n, 1) {
    for(int id : vec[i]) {
      insert(l[id], r[id], id);
    }
    cur = 0;
    solve(1, n);
    ans[i] = cur;
  }
  rep(i, 1, n)
    printf("%d\n", ans[i]);
  return 0;
}