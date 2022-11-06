// Author:  HolyK
// Created: Tue Sep 13 20:43:03 2022
#include <bits/stdc++.h>
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
  int n;
  std::cin >> n;
  std::vector<int> a(n);

  std::priority_queue<int> q;
  LL b = 0;
  
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    // a[i] -= i;
    q.push(a[i]);
    q.push(a[i]);
    b += q.top() - a[i];
    q.pop();
    a[i] = q.top();
  }

  std::cout << b << "\n";

  // for (int i = n - 1; i; i--) smin(a[i - 1], a[i]);
  // for (int i = 0; i < n; i++) {
  //   std::cout << a[i] + i << " \n"[i == n - 1];
  // }
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