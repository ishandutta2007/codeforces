#include <algorithm>
#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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
  std::vector<int> p, np(50000);
  for (int i = 2; i < 5e4; i++) {
    if (np[i]) continue;
    p.push_back(i);
    for (int j = i; j < 5e4; j += i) np[j] = 1; 
  }
  int t;
  std::cin >> t;
  
  while (t--) {
    int d;
    std::cin >> d;
    int u = *std::lower_bound(p.begin(), p.end(), 1 + d);
    int v = *std::lower_bound(p.begin(), p.end(), u + d);
    int k = *std::lower_bound(p.begin(), p.end(), v + d);
    if (u * v - v >= d)
      std::cout << u * v << "\n";
    else
      std::cout << 1LL * u * v * k << "\n";
  }
  return 0;
}