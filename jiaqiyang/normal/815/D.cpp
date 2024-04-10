#include <cstdio>
#include <tuple>
#include <algorithm>

typedef long long i64;

const int N = 500000 + 10;

int n, a, b, c;
std::tuple<int, int, int> p[N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

int min[2 * N], max[2 * N];
i64 sum[2 * N];

void apply(int l, int r, int x) {
  int id = pos(l, r);
  min[id] = max[id] = x;
  sum[id] = (r - l + 1LL) * x;
}

void release(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  if (max[pos(l, mid)] <= min[id]) apply(l, mid, min[id]);
  if (max[pos(mid + 1, r)] <= min[id]) apply(mid + 1, r, min[id]);
}

void update(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  min[id] = std::min(min[lch], min[rch]);
  max[id] = std::max(max[lch], max[rch]);
  sum[id] = sum[lch] + sum[rch];
}

void modify(int l, int r, int p, int q, int v) {
  if (min[pos(l, r)] >= v) return;
  if (p <= l && r <= q && max[pos(l, r)] <= v) {
    apply(l, r, v);
    return;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, q, v);
  if (q > mid) modify(mid + 1, r, p, q, v);
  update(l, r);
}

i64 ans;

void query(int l, int r, int p, int q, int v) {
  if (p <= l && r <= q) {
    int id = pos(l, r);
    if (max[id] <= v) {
      ans += (c - v) * (r - l + 1LL);
      return;
    }
    if (min[id] >= v) {
      ans += (r - l + 1LL) * c - sum[id];
      return;
    }
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) query(l, mid, p, q, v);
  if (q > mid) query(mid + 1, r, p, q, v);
  update(l, r);
}

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &c);
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    p[i] = std::make_tuple(x, y, z);
  }
  std::sort(p + 1, p + n + 1);
  static int suf[N][2];
  for (int i = n; i > 0; --i) {
    suf[i][0] = std::max(suf[i + 1][0], std::get<1>(p[i]));
    suf[i][1] = std::max(suf[i + 1][1], std::get<2>(p[i]));
  }
  ans = 0;
  for (int i = 1, j = 1; i <= a; ++i) {
    for (; j <= n && std::get<0>(p[j]) < i; ++j) modify(1, b, 1, std::get<1>(p[j]), std::get<2>(p[j]));
    int u = suf[j][0], v = suf[j][1];
    if (u < b) query(1, b, u + 1, b, v);
  }
  printf("%lld\n", ans);
  return 0;
}