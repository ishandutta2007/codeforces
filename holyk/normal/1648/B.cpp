// Author:  HolyK
// Created: Sun Mar  6 18:03:14 2022
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
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n);

  std::vector<int> s(c + 1);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s[a[i]]++;
  }

  for (int i = 1; i <= c; i++) {
    s[i] += s[i - 1];
  }

  for (int i = 1; i <= c; i++) {
    if (s[i] - s[i - 1] == 0) continue;
    for (int j = i; j <= c; j += i) {
      if ((s[std::min(c, j + i - 1)] - s[j - 1] > 0) && (s[j / i] - s[j / i - 1] <= 0)) {
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