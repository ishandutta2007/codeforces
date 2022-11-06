// Author:  HolyK
// Created: Wed Sep 21 17:59:12 2022
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

constexpr int N(3e5 + 5);
std::vector<PII> g[N]; // (to, edge_id)
int n, m;
std::vector<int> eulerWalk(int src = 0) {
  std::vector<int> d(n), cur(n), v(m), r, s = {src};
  d[src]++;  // to allow Euler paths , not just cycles
  while (!s.empty()) {
    int x = s.back(), &i = cur[x];
    if (i == g[x].size()) {
      r.push_back(x);
      s.pop_back();
      continue;
    }
    auto [y, e] = g[x][i++];
    if (!v[e]) {
      d[x]--, d[y]++;
      v[e] = 1;
      s.push_back(y);
    }
  }
  if (r.size() != m + 1) return {};
  for (int x : d) if (x < 0) return {};
  return {r.rbegin(), r.rend()};
}

void solve() {
  std::cin >> n >> m;
  std::vector<int> d(n);

  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    d[x] ^= 1, d[y] ^= 1;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  std::vector<int> odd;
  for (int i = 0; i < n; i++) {
    if (d[i]) odd.push_back(i);
  }

  for (int i = 0; i < odd.size(); i += 2) {
    int x = odd[i], y = odd[i + 1];
    g[x].push_back({y, m});
    g[y].push_back({x, m++});
  }

  if (m & 1) {
    g[0].push_back({0, m++});
  }

  auto ans = eulerWalk();

  std::cout << m << "\n";
  for (int i = 0; i + 1 < ans.size(); i++) {
    int x = ans[i] + 1, y = ans[i + 1] + 1;
    if (i & 1) {
      std::cout << x << " " << y << "\n";
    } else {
      std::cout << y << " " << x << "\n";
    }
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