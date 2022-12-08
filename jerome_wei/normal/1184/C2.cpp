#include <bits/stdc++.h>

using namespace std;

const int N = 8e6 + 10;
const int M = 6e6 + 10;
const int P = 3e5 + 10;

struct Point {
  int x, y;
} p[P];
vector<Point> g[M];
int ls[N], rs[N], val[N], tag[N], tot = 0, rt;

void pushnow(int t, int vl) {
  val[t] += vl;
  tag[t] += vl;
}

void pushdown(int t) {
  if (!ls[t]) ls[t] = ++tot;
  if (!rs[t]) rs[t] = ++tot;
  if (tag[t]) {
    pushnow(ls[t], tag[t]);
    pushnow(rs[t], tag[t]);
    tag[t] = 0;
  }
}

void pushup(int t) {
  val[t] = max(val[ls[t]], val[rs[t]]);
}

void modify(int &t, int l, int r, int ql, int qr, int vl) {
  if (!t) t = ++tot;
  if (ql <= l && r <= qr) {
    pushnow(t, vl);
    return;
  }
  pushdown(t);
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(ls[t], l, mid, ql, qr, vl);
  if (qr > mid) modify(rs[t], mid + 1, r, ql, qr, vl);
  pushup(t);
}

int n, r;

int main() {
  scanf("%d %d", &n, &r);
  int mx = 0, my = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &p[i].x, &p[i].y);
    int nx = p[i].x + p[i].y;
    int ny = p[i].y - p[i].x;
    p[i].x = nx;
    p[i].y = ny;
    mx = min(mx, nx);
    my = min(my, ny);
  }
  for (int i = 1; i <= n; i++) {
    p[i].x -= mx;
    p[i].y -= my;
    g[p[i].x].push_back((Point) {p[i].y, 1});
    g[p[i].x + 2 * r + 1].push_back((Point) {p[i].y, -1});
    // cout << p[i].x + 2 * r + 1 << "++" << endl;
  }
  int ans = 0;
  for (int i = 0; i < M; i++) if (g[i].size()) {
    for (auto cur : g[i]) {
      modify(rt, 0, N - 1, cur.x, cur.x + 2 * r, cur.y);
    }
    ans = max(ans, val[1]);
  }
  printf("%d\n", ans);
  return 0;
}