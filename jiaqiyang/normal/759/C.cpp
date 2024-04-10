#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int m, p[N], t[N], x[N];

int sum[2 * N], max[2 * N];
bool flag[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void update(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  sum[id] = sum[lch] + sum[rch];
  max[id] = std::max(max[lch] + sum[rch], max[rch]);
  flag[id] = flag[lch] || flag[rch];
}

void modify(int l, int r, int p, int v) {
  if (l == r) {
    int id = pos(l, r);
    sum[id] = max[id] = v;
    flag[id] = (v > 0);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, v); else modify(mid + 1, r, p, v);
  update(l, r);
}

int query(int l, int r, int v) {
  if (l == r) return l;
  int id = pos(l, r), mid = (l + r) >> 1;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  return flag[rch] && max[rch] > v ? query(mid + 1, r, v) : query(l, mid, v - sum[rch]);
}

int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &p[i], &t[i]);
    if (t[i]) scanf("%d", &x[p[i]]), modify(1, m, p[i], 1); else modify(1, m, p[i], -1);
    int cur = sum[pos(1, m)];
    if (max[pos(1, m)] <= 0) {
      puts("-1");
    } else {
      printf("%d\n", x[query(1, m, 0)]);
    }
  }
  return 0;
}