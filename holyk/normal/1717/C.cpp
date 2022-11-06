// Author:  HolyK
// Created: Fri Sep  2 22:46:24 2022
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

  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) std::cin >> b[i];

  for (int i = 0; i < n; i++) {
    if (b[i] < a[i]) {
      std::cout << "No\n";
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    if (b[i] - b[(i + 1) % n] > 1) {
      if (a[i] != b[i]) {
        std::cout << "No\n";
        return;
      }
    }
  }

  std::cout << "Yes\n";
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