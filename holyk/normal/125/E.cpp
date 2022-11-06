// Author:  HolyK
// Created: Sun Jul 31 15:16:31 2022
#include <algorithm>
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

struct Dsu {
  std::vector<int> f;
  void clear() {
    std::iota(f.begin(), f.end(), 0);
  } 
  Dsu(int n) : f(n) { clear(); }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    return !same(x, y) ? f[find(x)] = find(y), true : false;
  }
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::array<int, 4>> e1, e2;
  Dsu d(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x == 1 || y == 1) {
      e1.push_back({z, x, y, i});
    } else {
      e2.push_back({z, x, y, i});
    }
  }

  {
    std::vector<PII> e;
    for (auto &[z, x, y, _] : e1) e.push_back(std::minmax(x, y));
    std::sort(e.begin(), e.end());
    
    if (std::unique(e.begin(), e.end()) - e.begin() < k) {
      std::cout << "-1\n";
      return;
    }

    int c = 0;
    for (auto &[z, x, y, _] : e2) {
      c += d.merge(x, y);
    }
    int o = c;
    for (auto &[z, x, y, _] : e1) {
      c += d.merge(x, y);
    }
    if (c != n - 1 || c - o > k) {
      std::cout << "-1\n";
      return;
    }
  }
    
  std::sort(e1.begin(), e1.end());
  std::sort(e2.begin(), e2.end());

  auto cal = [&](int v) {
    decltype(e1) e3 = e1, e(m);
    for (auto &[z, x, y, _] : e3) z += v;
    for (int i = 0, j = 0, k = 0; k < m; k++) {
      if (j == e2.size() || i < e3.size() && e3[i][0] <= e2[j][0]) {
        e[k] = e3[i++];
      } else {
        e[k] = e2[j++];
      }
    }

    d.clear();
    LL sum = 0;
    int cnt = 0;
    for (auto &[z, x, y, _] : e) {
      if (d.merge(x, y)) {
        sum += z;
        if (x == 1 || y == 1) cnt++;
      }
    }
    return std::pair(sum, cnt);
  };
  int l = -3e4, r = 3e4;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if (cal(m).second >= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  {
    decltype(e1) e3 = e1, e(m);
    for (auto &[z, x, y, _] : e3) z += l;
    for (int i = 0, j = 0, k = 0; k < m; k++) {
      if (j == e2.size() || i < e3.size() && e3[i][0] <= e2[j][0]) {
        e[k] = e3[i++];
      } else {
        e[k] = e2[j++];
      }
    }

    d.clear();
    int cnt = 0;
    std::vector<int> ans;
    for (auto &[z, x, y, id] : e) {
      if (d.same(x, y)) continue;
      if (x != 1 && y != 1 || cnt < k) {
        ans.push_back(id + 1);
        d.merge(x, y);
        cnt += x == 1 || y == 1;
      }
    }
    assert(ans.size() == n - 1);
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}