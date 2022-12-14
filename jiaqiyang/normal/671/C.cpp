#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define fst first
#define snd second

typedef long long i64;

const int N = 200000 + 10;

int n, m, a[N];
std::vector<int> mem[N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

int min[2 * N];
bool flag[2 * N];
i64 sum[2 * N];

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    sum[id] = min[id] = l - 1;
    flag[id] = true;
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  build(l, mid);
  build(mid + 1, r);
  sum[id] = sum[lch] + sum[rch];
  min[id] = std::min(min[lch], min[rch]);
  flag[id] = (flag[lch] && flag[rch] && min[lch] == min[rch]);
}

void modify(int l, int r, int p, int q, int v) {
  if (p > q) return;
  int id = pos(l, r);
  if (v <= min[id]) return;
  if (p <= l && r <= q && flag[id]) {
    min[id] = v;
    sum[id] = (r - l + 1LL) * v;
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (flag[id]) {
    flag[lch] = flag[rch] = true;
    min[lch] = min[rch] = min[id];
    sum[lch] = (mid - l + 1LL) * min[id];
    sum[rch] = ((i64)r - mid) * min[id];
  }
  if (p <= mid) modify(l, mid, p, q, v);
  if (q > mid) modify(mid + 1, r, p, q, v);
  sum[id] = sum[lch] + sum[rch];
  min[id] = std::min(min[lch], min[rch]);
  flag[id] = (flag[lch] && flag[rch] && min[lch] == min[rch]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  m = *std::max_element(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        mem[j].push_back(i);
        if (j * j < a[i]) mem[a[i] / j].push_back(i);
      }
    }
  }
  static i64 f[N];
  build(1, n);
  for (int i = m; i > 0; --i) {
    if (mem[i].size() > 1) {
      modify(1, n, 1, mem[i][0], mem[i][mem[i].size() - 2] - 1);
      modify(1, n, mem[i][0] + 1, mem[i][1], mem[i].back() - 1);
      modify(1, n, mem[i][1] + 1, n, n);
    }
    f[i] = sum[pos(1, n)] - n * (n + 1LL) / 2 + n;
  }
  i64 ans = 0;
  for (int i = 1; i <= m; ++i) ans += (f[i] - f[i + 1]) * i;
  std::cout << ans << '\n';
  return 0;
}