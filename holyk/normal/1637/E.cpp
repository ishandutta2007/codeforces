// Author:  HolyK
// Created: Sat Feb 12 23:27:26 2022
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
  int n, m, t;
  std::cin >> n >> m;
  t = sqrt(n) + 1;
  std::vector<int> a(n), b;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::sort(a.begin(), a.end());

  std::vector<int> big;
  std::vector<int> cnt, max(t, -1e9);
  std::vector<std::multiset<int>> s(t);
  for (int i = 0, j, k = 0; i < n; i = j, k++) {  
    for (j = i + 1; j < n && a[i] == a[j]; j++) ;
    b.push_back(a[i]);
    cnt.push_back(j - i);
    if (cnt[k] >= t) {
      big.push_back(k);
    } else {
      s[cnt[k]].insert(a[i]);
    }
  }

  for (int i = 0; i < t; i++) {
    if (!s[i].empty()) {
      max[i] = *s[i].rbegin();
    }
  }
  
  std::vector<std::vector<int>> g(b.size());
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    x = std::lower_bound(b.begin(), b.end(), x) - b.begin();
    y = std::lower_bound(b.begin(), b.end(), y) - b.begin();
    g[x].push_back(y);
    g[y].push_back(x);
  }

  // std::cerr << "!!!\n";
  std::vector<int> vis(b.size(), -1);
  LL ans = 0;
  // std::cerr << t << "\n";
  for (int i = 0; i < b.size(); i++) {
    g[i].push_back(i);
    for (int j : g[i]) {
      vis[j] = i;
      if (cnt[j] < t) {
        int k = cnt[j];
        s[k].erase(s[k].find(b[j]));
        max[k] = s[k].empty() ? -2e9 : *s[k].rbegin();
      }
    }
    for (int j = 0; j < t; j++) {
      smax(ans, 1LL * (max[j] + b[i]) * (j + cnt[i]));
    }
    for (int j : big) {
      if (j >= i) break;
      if (vis[j] != i) {
        smax(ans, 1LL * (b[j] + b[i]) * (cnt[j] + cnt[i]));
      }
    }
    for (int j : g[i]) {
      if (cnt[j] < t) {
        int k = cnt[j];
        s[k].insert(b[j]);
        max[k] = s[k].empty() ? -2e9 : *s[k].rbegin();
      }
    }
  }
  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}