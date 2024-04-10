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

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<PII> v;
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && s[j] == s[i]; j++);
    v.push_back({s[i], j - i});
  }
  v.push_back({(int)'B', 0});
  int ans = n;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i].first == 'A') {
      int x = std::min(v[i].second, v[i + 1].second);
      v[i + 1].second -= x;
      ans -= x << 1;
      if (v[i].second == x && i) {
        v[i - 1].second += v[i + 1].second;
        v[i + 1].second = 0;
      }
      v[i].second = 0;
    }
  }
  for (auto [c, x] : v) {
    ans -= (x >> 1) << 1;
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}