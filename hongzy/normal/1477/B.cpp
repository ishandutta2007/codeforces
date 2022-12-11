#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 10;
int test, n, q, cov[N << 2], sum[N << 2], ql[N], qr[N];
char s[N], t[N];
void upd(int u) {
  sum[u] = sum[u << 1] + sum[u << 1 | 1];
}
void addtag(int u, int len, int c) {
  cov[u] = c; sum[u] = c ? len : 0;
}
void build(int u, int l, int r) {
  cov[u] = -1;
  if(l == r) {
    sum[u] = t[l] - '0';
    return ;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  upd(u);
}
void pd(int u, int l, int r) {
  if(~cov[u]) {
    int mid = (l + r) >> 1;
    addtag(u << 1, mid - l + 1, cov[u]);
    addtag(u << 1 | 1, r - mid, cov[u]);
    cov[u] = -1;
  }
}
void modify(int u, int l, int r, int ql, int qr, int c) {
  if(l == ql && r == qr) {
    addtag(u, r - l + 1, c); return ;
  }
  int mid = (l + r) >> 1; pd(u, l, r);
  if(qr <= mid) modify(u << 1, l, mid, ql, qr, c);
  else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, c);
  else {
    modify(u << 1, l, mid, ql, mid, c);
    modify(u << 1 | 1, mid + 1, r, mid + 1, qr, c);
  }
  upd(u);
}
int query(int u, int l, int r, int ql, int qr) {
  if(l == ql && r == qr) {
    return sum[u];
  }
  int mid = (l + r) >> 1; pd(u, l, r);
  if(qr <= mid) return query(u << 1, l, mid, ql, qr);
  if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
  return query(u << 1, l, mid, ql, mid) + query(u << 1 | 1, mid + 1, r, mid + 1, qr);
}
bool dfs(int u, int l, int r) {
  if(l == r) return s[l] - '0' == sum[u];
  pd(u, l, r);
  int mid = (l + r) >> 1;
  return dfs(u << 1, l, mid) && dfs(u << 1 | 1, mid + 1, r);
}
int main() {
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d%s%s", &n, &q, s + 1, t + 1);
    rep(i, 1, q) scanf("%d%d", ql + i, qr + i);
    bool mark = 1;
    build(1, 1, n);
    per(i, q, 1) {
      int cnt = qr[i] - ql[i] + 1;
      int sum = query(1, 1, n, ql[i], qr[i]);
      if(cnt % 2 == 0 && sum == cnt / 2) {
        mark = 0; break ;
      }
      int c = sum < cnt - sum ? 0 : 1;
      modify(1, 1, n, ql[i], qr[i], c);
    }
    if(mark && !dfs(1, 1, n)) mark = 0;
    puts(mark ? "YES" : "NO");
  }
  return 0;
}