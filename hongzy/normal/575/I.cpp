#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 5005;
const int M = 1e6 + 10;
struct node { int d, x, y, len; } a[M];
struct bit {
  int c[N + N][N], n, m;
  void init(int x, int y) { n = x; m = y; }
  void clear() {
    rep(i, 1, n) rep(j, 1, m) c[i][j] = 0;
  }
  void modify(int x, int y, int v) {
    if(y > m) return ;
    for(int i = x; i <= n; i += i & -i)
      for(int j = y; j <= m; j += j & -j)
        c[i][j] += v;
  }
  void modify(int l, int r, int x, int y, int v) {
    if(l > r || x > y) return ;
    modify(l, x, v);
    modify(r + 1, x, -v);
    modify(l, y + 1, -v);
    modify(r + 1, y + 1, v);
  }
  int query(int x, int y) {
    int res = 0;
    for(int i = x; i >= 1; i &= i - 1)
      for(int j = y; j >= 1; j &= j - 1)
        res += c[i][j];
    return res;
  }
} bx, by;
int n, q, ans[M];
void work(int op) {
  bx.clear(); by.clear();
  rep(i, 1, q) {
    int x = a[i].x, y = a[i].y;
    if(!a[i].d) {
      ans[i] += bx.query(x + y, x) + by.query(x + y, y);
    } else if(a[i].d == op) {
      bx.modify(x + y, x + y + a[i].len, 1, n, 1);
      bx.modify(x + y, x + y + a[i].len, 1, x - 1, -1);
      by.modify(x + y, x + y + a[i].len, 1, y - 1, -1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &q);
  bx.init(n + n, n);
  by.init(n + n, n);
  int op;
  rep(i, 1, q) {
    scanf("%d", &op);
    if(op == 1) scanf("%d%d%d%d", &a[i].d, &a[i].x, &a[i].y, &a[i].len);
    if(op == 2) scanf("%d%d", &a[i].x, &a[i].y);
  }
  work(1);
  rep(i, 1, q) a[i].y = n - a[i].y + 1;
  work(2);
  rep(i, 1, q) a[i].x = n - a[i].x + 1;
  work(4);
  rep(i, 1, q) a[i].y = n - a[i].y + 1;
  work(3);
  rep(i, 1, q) if(!a[i].d)
    printf("%d\n", ans[i]);
  return 0;
}