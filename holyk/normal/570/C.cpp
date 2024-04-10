#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::string a;
  std::set<PII> s;
  std::cin >> n >> m >> a;
  int ans = 0;
  auto get = [&](int x) {
    auto t = s.lower_bound({x + 1, 0});
    PII res = *--t;
    s.erase(t);
    ans -= res.second - res.first;
    return res;
  };
  for (int i = 0, j; i < n; i = j) {
    if (a[i] != '.') {
      j = i + 1;
      continue;
    }
    for (j = i; j < n && a[j] == '.'; j++);
    s.insert({i, j - 1});
    ans += j - i - 1;
  }
  while (m--) {
    int x; char c;
    std::cin >> x >> c;
    x--;
    if (a[x] != '.' && c != '.' || a[x] == c) {
      std::cout << ans << "\n";
      continue;
    }
    if (a[x] == '.') {
      auto [l, r] = get(x);
      if (x > l) s.insert({l, x - 1}), ans += x - 1 - l;
      if (r > x) s.insert({x + 1, r}), ans += r - x - 1;
    } else {
      int l = x, r = x;
      if (x && a[x - 1] == '.')
        l = get(x - 1).first;
      if (x < n && a[x + 1] == '.')
        r = get(x + 1).second;
      s.insert({l, r}), ans += r - l;
    }
    a[x] = c;
    std::cout << ans << "\n";
  }
  return 0;
}