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


void tmp(int n) {

  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 1);
  int cnt = 0;
  do [&]{
    for (int i = 1; i < n; i++) if (p[i - 1] - 1 > p[i]) return;
    std::cout << ++cnt << ": ";
    for (auto x : p) std::cout << x << " ";std::cout << "\n";
    
  }();
  while (std::next_permutation(p.begin(), p.end())); 
  // std::cout << n << " " << cnt << "\n";
}
int main() {
  // freopen("t.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // for (int i = 1; i <= 11; i++) tmp(i);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    LL k;
    std::cin >> n >> k;
    
    LL pw = 1;
    for (int i = 1; i <= n - 1; i++) {
      pw *= 2;
      if (pw >= k) break;
    }
    if (pw < k) {
      std::cout << "-1\n";
      continue;
    }

    std::function<void(int, int, LL)> solve = [&](int l, int r, LL k) {
      if (l > r) return;
      if (k <= 0) {
        while (l <= r) std::cout << l++ << " ";
        return;
      }
      // dbg("%d %d %lld\n", l, r, k);
      int u = std::__lg(k) + 1;
      while (r - l - 1 >= u) std::cout << l++ << " ";
      // dbg("?? %d\n", l);
      int t = l;
      while (k > 1LL << (r - t - 1)) k -= 1LL << (r - t++ - 1);
      for (int i = std::min(r, t); i >= l; i--) std::cout << i << " ";
      solve(t + 1, r, k);
    };
    solve(1, n, k);
    std::cout << "\n";  
  }
  return 0;
}