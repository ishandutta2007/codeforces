// Author:  HolyK
// Created: Tue Jul 26 09:00:35 2022
#include <bits/stdc++.h>
#include <string>

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
  std::string a, b, c;
  std::getline(std::cin, a);
  std::getline(std::cin, b);
  std::getline(std::cin, c);
  auto get = [&](std::string s){
    int cnt = 0;
    for (char c : s) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        cnt++;
      }
    }
    return cnt;
  };
  std::cout << (get(a) == 5 && get(b) == 7 && get(c) == 5 ? "YES\n" : "NO\n");
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