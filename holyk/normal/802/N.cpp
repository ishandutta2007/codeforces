// Author:  HolyK
// Created: Sun Jul 31 16:14:22 2022
#include <bits/stdc++.h>
#include <functional>
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
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) std::cin >> b[i];

  auto cal = [&](LL x) {
    using P = std::pair<LL, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> q;
    LL sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      q.push({a[i], -1});
      if (q.top().first + b[i] + x <= 0) {
        cnt -= q.top().second; 
        sum += q.top().first + b[i] + x;
        q.pop();
        q.push({-b[i] - x, 0});
      }
    }
    return std::pair(sum, cnt);
  };

  LL l = -2e9, r = 0;
  while (l < r) {
    LL m = l + r + 1 >> 1;
    if (cal(m).second >= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  // std::cerr << l << "\n";
  std::cout << cal(l).first - 1LL * k * l << "\n";
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