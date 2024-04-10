// Author:  HolyK
// Created: Sun Sep 18 15:59:52 2022
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

constexpr int N(1e5 + 5);
int n, m, l[N];

#define ls o << 1
#define rs o << 1 | 1

using A = std::array<int, 2>;
A max[N << 2], tag[N << 2];

void app(int o, const A &a) {
  if (max[o][0] >= a[0]) {
    max[o][0] = a[1];
    if (tag[o][0] == -1 || a[0] <= tag[o][0] || tag[o][1] < a[0]) {
      tag[o] = a;
    } else {
      tag[o][1] = a[1];
    }
  }
}

void pushdown(int o) {
  if (tag[o][0] != -1) {
    app(ls, tag[o]);
    app(rs, tag[o]);
    tag[o][0] = -1;
  }
}

void pushup(int o) {
  max[o][0] = std::max(max[ls][0], max[rs][0]);
  max[o][1] = 0;
  auto f = [&](int x) {
    if (x != max[o][0]) smax(max[o][1], x);
  };
  f(max[ls][0]), f(max[ls][1]), f(max[rs][0]), f(max[rs][1]);
}

void build(int o, int l, int r) {
  tag[o][0] = -1;
  if (l == r) {
    max[o][0] = l;
    max[o][1] = 0;
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m);
  build(rs, m + 1, r);
  pushup(o);
}

void update(int o, int l, int r, int x, int y, const A &a) {
  if (max[o][0] < a[0]) return;
  if (x <= l && r <= y && max[o][0] >= a[0] && a[0] > max[o][1]) {
    return app(o, a);
  }
  pushdown(o);
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, a);
  if (y > m) update(rs, m + 1, r, x, y, a);
  pushup(o);
}

int ask(int o, int l, int r, int x) {
  if (l == r) return max[o][0];
  int m = l + r >> 1;
  pushdown(o);
  return x <= m ? ask(ls, l, m, x) : ask(rs, m + 1, r, x);
}

void solve() {
  std::cin >> n >> m;
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    l[y] = x;
  }

  std::cin >> m;
  std::vector<std::array<int, 3>> q(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    q[i] = {y, x, i};
  }

  std::sort(q.begin(), q.end());
  build(1, 1, n);

  std::vector<int> ans(m);
  int i = 1;
  for (auto &[y, x, id] : q) {
    for (; i <= y; i++) {
      if (!l[i]) continue;
      update(1, 1, n, 1, l[i], {l[i], i});
    }
    ans[id] = ask(1, 1, n, x);
  }

  for (auto z : ans) std::cout << z << "\n";
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