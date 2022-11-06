// Author:  HolyK
// Created: Wed May 11 10:44:39 2022
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

template <class T>
struct RangeFen {
  std::vector<std::array<T, 2>> c;
  RangeFen(int n) : c(n) {}
  void add(int p, T x) {
    for (int i = p; i < c.size(); i |= i + 1) {
      c[i][0] -= p * x;
      c[i][1] += x;
    }
  }
  T ask(int p) {
    T r = 0;
    for (int i = p; i; i &= i - 1) {
      r += c[i - 1][0] + c[i - 1][1] * p;
    }
    return r;
  }
  void add(int l, int r, T x) { add(l, x), add(r, -x); }
  T ask(int l, int r) { return ask(r) - ask(l); }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), pos(n + 1);
  for (int i = 0; i < n; i++) std::cin >> a[i], pos[a[i]] = i;

  std::vector<int> left(n + 1), right(n + 1);
  {
    std::vector<int> s(n);
    for (int i = 0, t = 0; i < n; i++) {
      while (t && a[s[t - 1]] < a[i]) t--;
      left[a[i]] = t ? s[t - 1] : -1;
      s[t++] = i;
    }
    for (int i = n - 1, t = 0; i >= 0; i--) {
      while (t && a[s[t - 1]] < a[i]) t--;
      right[a[i]] = t ? s[t - 1] : n;
      s[t++] = i;
    }
  }

  std::vector<std::vector<PII>> it(n + 1);
  for (int i = 1; i * (i + 1) <= n; i++) {
    for (int j = i + 1; i * j <= n; j++) {
      int k = i * j, l = std::min({pos[i], pos[j], pos[k]}), r = std::max({pos[i], pos[j], pos[k]});
      // std::cerr << " " << i << " " << j << " " << l << " " << r << " " << left[k] << " " << right[k] << "\n";
      if (l > left[k] && r < right[k]) {
        // std::cerr << l << " " << r << " " << k << "\n";
        it[k].push_back({r, l});
      }
    }
  }

  std::vector<std::vector<std::array<int, 3>>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::sort(it[i].begin(), it[i].end());
    
    for (int j = 0, l = 0, r; j < it[i].size(); j++) {
      smax(l, it[i][j].second);
      r = j + 1 < it[i].size() ? it[i][j + 1].first : right[i];
      g[it[i][j].first].push_back({left[i] + 1, l, 1});
      g[r].push_back({left[i] + 1, l, -1});
    }
  }

  std::vector<LL> ans(m);
  std::vector<std::vector<PII>> q(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    l--, r--;
    q[r].push_back({l, i});
  }
  
  RangeFen<LL> t1(n), t2(n);
  for (int i = 0; i < n; i++) {
    for (auto [l, r, k] : g[i]) {
      // std::cerr << i << " " << l << " " << r << " " << k << "\n";
      t1.add(l, r + 1, k), t2.add(l, r + 1, k * i);
    }
    for (auto [l, id] : q[i]) {
      ans[id] = t1.ask(l, i + 1) * (i + 1) - t2.ask(l, i + 1);
    }
  }

  for (LL x : ans) std::cout << x << "\n";
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