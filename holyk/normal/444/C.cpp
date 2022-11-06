#include <bits/stdc++.h>
using LL = long long;

constexpr int N(1e5 + 5);
struct Node {
  bool eq;
  int c, tag;
  LL sum, add;
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void pushup(int o) {
  t[o].eq = t[ls].eq && t[rs].eq && t[ls].c == t[rs].c;
  t[o].c = t[ls].c;
  t[o].sum = t[ls].sum + t[rs].sum;
}
void add(int o, LL z, int len) {
  t[o].add += z;
  t[o].sum += z * len;
}
void update(int o, int z) {
  t[o].tag = t[o].c = z;
}
void pushdown(int o, int len) {
  if (t[o].add) {
    add(ls, t[o].add, len - (len >> 1));
    add(rs, t[o].add, len >> 1);
    t[o].add = 0;
  }
  if (t[o].tag != -1) {
    update(ls, t[o].tag);
    update(rs, t[o].tag);  
    t[o].tag = -1;
  }
}
void update(int o, int l, int r, int x, int y, int z) {
  
  if (x <= l && r <= y && t[o].eq) {
    add(o, abs(z - t[o].c), r - l + 1);
    update(o, z);
    return;
  }
  assert(l < r);
  pushdown(o, r - l + 1);
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}
LL ask(int o, int l, int r, int x, int y) {
  if (x > r || y < l) return 0;
  if (x <= l && r <= y) return t[o].sum;
  pushdown(o, r - l + 1);
  int m = l + r >> 1;
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
void build(int o, int l, int r) {
  t[o].tag = -1;
  if (l == r) {
    t[o].eq = true;
    t[o].c = l;
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  build(1, 1, n);
  while (m--) {
    int opt, x, y, z;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      std::cin >> z;
      update(1, 1, n, x, y, z);
    } else {
      std::cout << ask(1, 1, n, x, y) << "\n";
    }
  }
  return 0;
}