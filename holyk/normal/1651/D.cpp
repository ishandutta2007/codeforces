// Author:  HolyK
// Created: Thu Mar 10 23:16:30 2022
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

void solve() {
  int n;
  std::cin >> n;
  std::map<PII, PII> ul, ur, dl, dr;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
  }

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });

  for (int i : p) {
    int x = a[i], y = b[i];
    PII t(x - 1, y + 1);
    ul[{x, y}] = ul.count(t) ? ul[t] : t;
    t.second = y - 1;
    dl[{x, y}] = dl.count(t) ? dl[t] : t;
  }
  std::reverse(p.begin(), p.end());
  for (int i : p) {
    int x = a[i], y = b[i];
    PII t(x + 1, y + 1);
    ur[{x, y}] = ur.count(t) ? ur[t] : t;
    t.second = y - 1;
    dr[{x, y}] = dr.count(t) ? dr[t] : t;
  }

  std::vector<PII> ans(n);
  std::map<PII, int> dist;
  for (int i : p) {
    int x = a[i], y = b[i];

    auto dis = [&](int u, int v) {
      return std::abs(x - u) + std::abs(y - v);
    };
    for (int j = std::max(1, dist[{x + 1, y}] - 1); ; j++) {
      auto it = ur.find({x - j, y});
      if (it == ur.end()) {
        ans[i] = {x - j, y};
        break;
      } else {
        auto [u, v] = it->second;
        if (dis(u, v) == j) {
          ans[i] = {u, v};
          break;
        }
      }
      {
        auto [u, v] = dr[{x, y + j}];
        if (dis(u, v) == j) {
          ans[i] = {u, v};
          break;
        }
      }
      {
        auto [u, v] = dl[{x + j, y}];
        
        if (dis(u, v) == j) {
          ans[i] = {u, v};
          break;
        }
      }
      {
        auto [u, v] = ul[{x, y - j}];
        if (dis(u, v) == j) {
          ans[i] = {u, v};
          break;
        }
      }
    }

    dist[{x, y}] = dis(ans[i].first, ans[i].second);
  }

  for (auto [x, y] : ans) {
    std::cout << x << " " << y << "\n";
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