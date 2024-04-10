#include <bits/stdc++.h>

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e5 + 5);

LL sum[N << 2];
int max[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void pushup(int o) {
  sum[o] = sum[ls] + sum[rs];
  max[o] = std::max(max[ls], max[rs]);
}
void build(int o, int l, int r) {
  if (l == r) {
    std::cin >> max[o];
    sum[o] = max[o];
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    sum[o] = max[o] = y;
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  pushup(o);
}
void update(int o, int l, int r, int x, int y, int z) {
  if (max[o] < z) return;
  if (l == r) {
    sum[o] = max[o] %= z;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}
LL ask(int o, int l, int r, int x, int y) {
  if (x > r || y < l) return 0;
  if (x <= l && r <= y) return sum[o];
  int m = l + r >> 1;
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  build(1, 1, n);
  while (m--) {
    int opt, x, y;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      std::cout << ask(1, 1, n, x, y) << "\n";
    } else if (opt == 2) {
      int z;
      std::cin >> z;
      update(1, 1, n, x, y, z);
    } else {
      update(1, 1, n, x, y);
    }
  }
  return 0;
}