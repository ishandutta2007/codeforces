#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

LL solve(std::string s, int x, int y) {
  int n = s.length();
  std::vector<int> c(n);
  LL ans, sum = 0;
  for (int i = 0; i < n; i++) {
    if (i) c[i] += c[i - 1];
    if (s[i] == '0') {
      c[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      sum += 1LL * (i + 1 - c[i]) * y + 1LL * (n - 1 - i - c[n - 1] + c[i]) * x;
  }
  ans = sum;
  for (int i = 0, p = 0; i < n; i++) {
    if (s[i] != '?') continue;
    p++;
    sum += 1LL * (i + 1 - c[i] - p) * y + 1LL * (n - i - 1 - c[n - 1] + c[i]) * x;
    sum -= 1LL * x * (c[i] + p - 1) + 1LL * y * (c[n - 1] - c[i]);
    smin(ans, sum);
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s; std::cin >> s;
  int x, y;
  std::cin >> x >> y;
  LL ans = solve(s, x, y);
  for (auto &c : s) {
    if (c == '0') c = '1';
    else if (c == '1') c = '0';
  }
  smin(ans, solve(s, y, x));
  std::cout << ans;
  return 0;
}