// Author:  HolyK
// Created: Sun May 30 22:57:35 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> p;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x == 1) {
	p.push_back(1);
      } else {

	while (p.size() && p.back() != x - 1) p.pop_back();
	assert(p.size());
	p.back() = x;
      }
      
      for (int j = 0; j < p.size(); j++) std::cout << p[j] << ".\n"[j == p.size() - 1];
    }
  }
  return 0;
}
/*
2
4
1
1
2
3
9
1
1
1
2
2
1
2
1
2

 */