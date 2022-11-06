// Author:  HolyK
// Created: Fri May 20 15:25:04 2022
#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

#define ls o << 1
#define rs o << 1 | 1

constexpr int N(2e5 + 5);

LL max[N << 2], add[N << 2];
void apply(int o, LL x) {
  max[o] += x, add[o] += x;
}
void pushdown(int o) {
  if (add[o]) {
    apply(ls, add[o]), apply(rs, add[o]), add[o] = 0;
  }
}

void pushup(int o) {
  max[o] = std::max(max[ls], max[rs]);
}

void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return apply(o, z);
  int m = l + r >> 1;
  pushdown(o);
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}

int ask(int o, int l, int r) {
  if (max[o] < 0) return -1;
  if (l == r) return max[o] == 0 ? l : -1;
  pushdown(o);
  int m = l + r >> 1, ans = ask(ls, l, m);
  if (ans == -1) ans = ask(rs, m + 1, r);
  return ans;
}

int a[N];
LL s[N];
void build(int o, int l, int r) {
  if (l == r) {
    max[o] = a[l] - s[l - 1];
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  build(1, 1, n);

  while (m--) {
    int x, y;
    std::cin >> x >> y;
    update(1, 1, n, x, x, y - a[x]);
    if (x < n) update(1, 1, n, x + 1, n, a[x] - y);
    a[x] = y;
    std::cout << ask(1, 1,n) << "\n";
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}