// Author:  HolyK
// Created: Fri May 20 14:58:15 2022
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

constexpr int T(512);
int root[105], f[T];
int find(int x) {
  while (x != f[x]) x = f[x] = f[f[x]];
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int m;
  std::cin >> m;
  std::vector<std::array<int, 4>> q(m);
  for (auto &[l, r, x, y] : q) std::cin >> l >> r >> x >> y, l--;

  for (int l = 0; l < n; l += T) {
    int r = std::min(n, l + T);

    auto build = [&] {
      for (int i = l; i < r; i++) root[a[i]] = i - l;
      for (int i = l; i < r; i++) f[i - l] = root[a[i]];
    };

    memset(root, 0, sizeof root);
    build();

    for (auto &[ql, qr, x, y] : q) {
      if (qr <= l || ql >= r) continue;
      if (ql <= l && r <= qr) {
        int u = find(root[x]), v = find(root[y]);
        if (a[l + u] != x) continue;
        a[l + u] = y, root[y] = u;
        if (a[l + v] == y) f[v] = u;
      } else {
        for (int i = l; i < r; i++) a[i] = a[l + find(i - l)];
        for (int i = std::max(ql, l); i < r && i < qr; i++) {
          if (a[i] == x) a[i] = y;
        }
        build();
      }
    }

    for (int i = l; i < r; i++) {
      std::cout << a[l + find(i - l)] << " \n"[i + 1 == n];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}