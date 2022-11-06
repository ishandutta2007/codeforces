// Author:  HolyK
// Created: Fri May 20 17:19:12 2022
#include <bits/stdc++.h>
#include <queue>

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

void solve() {
  int n, q, s, k;
  std::cin >> n >> q >> s;
  s--;
  k = 1 << std::__lg(n * 2 - 1);
  
  std::vector<std::vector<PII>> g(n + (k - 1) * 2);
  auto add = [&](int x, int y, int z) {
    g[x].push_back({y, z});
    // std::cerr << "add " << x << " " << y << " " << z << "\n";
  };
  
  for (int i = 2; i < k; i++) {
    add(n - 1 + i, n - 1 + i / 2, 0);
    add(n + k - 2 + i / 2, n + k - 2 + i, 0);
  }
  for (int i = 0; i < n; i++) {
    add(i, n - 1 + (i + k >> 1), 0);
    add(n + k - 2 + (i + k >> 1), i, 0);
  }

  while (q--) {
    int t, l, r, x, w;
    std::cin >> t;
    if (t == 1) {
      std::cin >> l >> r >> w;
      l--, r--;
      add(l, r, w);
    } else if (t == 2) {
      std::cin >> x >> l >> r >> w;
      x--, l--;
      for (l += k, r += k; l < r; l >>= 1, r >>= 1) {
        if (l & 1) add(x, l >= k ? l - k : n + k - 2 + l, w), l++;
        if (r & 1) r--, add(x, r >= k ? r - k : n + k - 2 + r, w);
      }
    } else {
      std::cin >> x >> l >> r >> w;
      x--, l--;
      for (l += k, r += k; l < r; l >>= 1, r >>= 1) {
        if (l & 1) add(l >= k ? l - k : n - 1 + l, x, w), l++;
        if (r & 1) r--, add(r >= k ? r - k : n - 1 + r, x, w);
      }
    }
  }

  {
    std::priority_queue<std::pair<LL, int>> q;
    int nn = g.size();
    std::vector<LL> d(nn, 1e18);
    std::vector<bool> vis(nn);
    
    d[s] = 0;
    q.push({0LL, s});
    while (!q.empty()) {
      auto [_, x] = q.top();
      q.pop();
      if (vis[x]) continue;
      vis[x] = true;
      for (auto [y, z] : g[x]) {
        if (smin(d[y], d[x] + z)) {
          q.push({-d[y], y});
        }
      }
    }

    for (int i = 0; i < n; i++) std::cout << (d[i] == 1e18 ? -1 : d[i]) << " \n"[i + 1 == n];
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}