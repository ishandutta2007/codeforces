#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 100000 + 10, S = 50 * N;

int n, m, h[N], sorted[N], root[N];

struct Info {
  int ls, rs, mx;
  bool flag;
  inline void clear() {
    ls = rs = mx = 0;
    flag = false;
  }
} info[S];

inline Info operator+ (const Info &lhs, const Info &rhs) {
  Info res;
  res.mx = std::max(lhs.mx, rhs.mx);
  res.ls = lhs.ls;
  if (lhs.flag) res.ls += rhs.ls;
  res.rs = rhs.rs;
  if (rhs.flag) res.rs += lhs.rs;
  res.flag = (lhs.flag && rhs.flag);
  res.mx = std::max(res.mx, lhs.rs + rhs.ls);
  return res;
}

int lch[S], rch[S], tot;

int modify(int id, int l, int r, int p) {
  int res = ++tot;
  lch[res] = lch[id], rch[res] = rch[id];
  if (l == r) {
    info[res].ls = info[res].rs = info[res].mx = 1;
    info[res].flag = true;
    return res;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) lch[res] = modify(lch[id], l, mid, p); else rch[res] = modify(rch[id], mid + 1, r, p);
  info[res] = info[lch[res]] + info[rch[res]];
  return res;
}

Info res;

void query(int id, int l, int r, int p, int q) {
  if (p <= l && r <= q) {
    res = res + info[id];
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) query(lch[id], l, mid, p, q);
  if (q > mid) query(rch[id], mid + 1, r, p, q);
}

void init() {
  for (int i = 1; i <= n; ++i) sorted[i] = h[i];
  std::sort(sorted + 1, sorted + n + 1);
  m = std::unique(sorted + 1, sorted + n + 1) - sorted - 1;
  for (int i = 1; i <= n; ++i) h[i] = std::lower_bound(sorted + 1, sorted + m + 1, h[i]) - sorted;
  static std::vector<int> pool[N];
  for (int i = 1; i <= n; ++i) pool[h[i]].push_back(i);
  for (int i = m; i > 0; --i) {
    root[i] = root[i + 1];
    for (int j = 0; j < pool[i].size(); ++j) root[i] = modify(root[i], 1, n, pool[i][j]);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
  init();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    int l = 1, r = m;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      res.clear();
      query(root[mid], 1, n, x, y);
      if (res.mx >= z) l = mid; else r = mid - 1;
    }
    printf("%d\n", sorted[l]);
  }
  return 0;
}