// Author:  HolyK
// Created: Mon Aug  9 23:31:36 2021
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

constexpr int N(6e5 + 5);
#define ls o << 1
#define rs o << 1 | 1
PII max[N << 2], tag[N << 2];
void pushup(int o) {
  max[o] = std::max({max[ls], max[rs], tag[o]});
}
void update(int o, int l, int r, int x, int y, PII z) {
  smax(max[o], z);
  if (x <= l && r <= y) {
    smax(tag[o], z);
    return;
  }
  int m = l + r >> 1;
  if (x < m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m, r, x, y, z);
}
PII ask(int o, int l, int r, int x, int y) {
  if (r <= x || y <= l) return {0, 0};
  if (x <= l && r <= y) return max[o];
  int m = l + r >> 1;
  return std::max({ask(ls, l, m, x, y), ask(rs, m, r, x, y), tag[o]});
}
std::vector<PII> g[N];
PII f[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a;
  while (m--) {
    int x, l, r;
    std::cin >> x >> l >> r;
    a.push_back(l);
    a.push_back(r + 1);
    g[x].push_back({l, r + 1});
  }
  std::sort(a.begin(), a.end());
  a.resize(std::unique(a.begin(), a.end()) - a.begin());
  PII ans;
  for (int i = 1; i <= n; i++) {
    for (auto &[l, r] : g[i]) {
      l = std::lower_bound(a.begin(), a.end(), l) - a.begin();
      r = std::lower_bound(a.begin(), a.end(), r) - a.begin();
      smax(f[i], ask(1, 0, a.size(), l, r));
    }
    f[i].first++;
    
    auto t = f[i];
    t.second = i;
    smax(ans, t);
    for (auto [l, r] : g[i]) {
      update(1, 0, a.size(), l, r, t);
    }
  }
  std::vector<int> vis(n + 1);
  for (int i = ans.second; i; i = f[i].second) vis[i] = 1;
  std::cout << n - ans.first << "\n";
  std::vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      v.push_back(i);
    }
  }
  assert(v.size() == n - ans.first);
  for (int i : v) std::cout << i << " ";
  return 0;
}