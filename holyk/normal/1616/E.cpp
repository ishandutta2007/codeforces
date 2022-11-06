// Author:  HolyK
// Created: Thu Dec 30 16:38:31 2021
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
  std::string s, t;
  std::cin >> n >> s >> t;
  
  std::queue<int> q[26];
  for (int i = 0; i < n; i++) {
    q[s[i] - 'a'].push(i);
  }
  
  LL ans = 1e18, now = 0;
  std::vector<int> c(n + 1);
  auto add = [&](int p, int x) {
    for (p++; p <= n; p += p & -p) c[p] += x;
  };
  auto ask = [&](int p) {
    int r = 0;
    for (p++; p; p -= p & -p) r += c[p];
    return r;
  };
  for (int i = 1; i <= n; i++) {
    c[i] = i & -i;
  }
  for (int i = 0; i < n; i++) {
    int x = t[i] - 'a';
    for (int j = 0; j < x; j++) {
      if (q[j].size()) {
        int k = q[j].front();
        smin(ans, now + ask(k) - 1);
      }
    }
    if (q[x].empty()) {
      break;
    }
    int k = q[x].front();
    now += ask(k) - 1;
    add(k, -1);
    q[x].pop();
  }
  if (ans == 1e18) {
    std::cout << "-1\n";
  } else {
    std::cout << ans << "\n";
  }
}

int main() { 
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}