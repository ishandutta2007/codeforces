// Author:  HolyK
// Created: Sat Feb 12 22:44:13 2022
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
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if (n == 3 && a[1] % 2) {
    std::cout << "-1\n";
    return;
  }

  bool ok = false;
  LL s = 0;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > 1) {
      ok = true;
    }
    s += a[i] + 1 >> 1;
  }
  if (ok) {
    std::cout << s << "\n";
  } else {
    std::cout << "-1\n";
  }
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