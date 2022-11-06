// Author:  HolyK
// Created: Tue Jul 12 19:48:18 2022
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
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
    b[a[i]] = i;
  }
  std::vector<int> s, l(n), r(n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.back()] <= a[i]) s.pop_back();
    l[i] = s.empty() ? 0 : s.back() + 1;
    s.push_back(i);
  }
  s.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && a[s.back()] <= a[i]) s.pop_back();
    r[i] = s.empty() ? n - 1 : s.back() - 1;
    s.push_back(i);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i - l[i] < r[i] - i) {
      for (int j = l[i]; j < i; j++) {
        int p = b[a[i] - 1 - a[j]];
        ans += i < p && p <= r[i];
      }
    } else {
      for (int j = i + 1; j <= r[i]; j++) {
        int p = b[a[i] - 1 - a[j]];
        ans += l[i] <= p && p < i;
      }
    }
  }
  std::cout << ans << "\n";
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