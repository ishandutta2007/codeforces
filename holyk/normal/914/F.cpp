// Author:  HolyK
// Created: Thu Aug 25 00:51:20 2022
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

constexpr int N(1e5 + 5);
std::bitset<N> b[26], r;
void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    b[s[i] - 'a'].set(i);
  }

  int q;
  std::cin >> q;
  while (q--) {
    int opt, x, y;
    std::string t;
    std::cin >> opt;
    if (opt == 1) {
      std::cin >> x >> t;
      x--;
      b[s[x] - 'a'].flip(x);
      s[x] = t[0];
      b[s[x] - 'a'].flip(x);
    } else {
      std::cin >> x >> y >> t;
      x--, y -= t.size() - 1;
      if (x >= y) {
        std::cout << "0\n";
        continue;
      }
      r.set();
      for (int i = 0; i < t.size(); i++) {
        r &= b[t[i] - 'a'] >> i;
      }
      std::cout << (r >> x).count() - (r >> y).count() << "\n";
    }
  }
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