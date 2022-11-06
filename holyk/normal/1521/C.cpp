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
int n;
int ask(int t, int i, int j) {
  std::cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << (t == 1 ? n - 1 : 1) << "\n";
  std::cout.flush();
  int v;
  std::cin >> v;
  if (t == 1 && v == n - 1) {
    std::cout << "? " << t << " " << j + 1 << " " << i + 1 << " " << n - 1 << "\n";
    std::cout.flush();
    int c;
    std::cin >> c;
    return std::max(v, c);
  }
  if (t == 2 && v == 2) {
    std::cout << "? " << t << " " << j + 1 << " " << i + 1 << " " << 1 << "\n";
    std::cout.flush();
    int c;
    std::cin >> c;
    return std::min(v, c);
  }
  return v;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::vector<int> p(n);
    int i = 0;
    for (; i + 2 < n; i += 3) {
      p[0 + i] = ask(1, 0 + i, 1 + i);
      p[1 + i] = ask(2, 0 + i, 1 + i);
      p[2 + i] = ask(1, 1 + i, 2 + i);
      if (p[2 + i] == p[1 + i] || p[2 + i] == p[0 + i]) {
        if (p[2 + i] == p[0 + i]) std::swap(p[0 + i], p[1 + i]);
        p[2 + i] = ask(2, 1 + i, 2 + i);
      } else {
        if (ask(2, 1 + i, 2 + i) != p[1 + i]) std::swap(p[0 + i], p[1 + i]);
      }
    }
    for (; i < n; i++) {
      p[i] = ask(1, i - 1, i);
      if (p[i] == p[i - 1]) p[i] = ask(2, i - 1, i);
    }
    std::cout << "!";
    for (int x : p) std::cout << " " << x;
    std::cout << "\n";
    std::cout.flush();
  }
  return 0;
}