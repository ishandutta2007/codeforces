#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
typedef long long LL;
typedef std::pair<int, int> PII;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; LL t;
  std::string s;
  std::cin >> n >> t >> s;
  std::vector<LL> a(n);
  for (int i = 0; i < n; i++)
    a[i] = 1LL << s[i] - 'a';
  t = t - a[n - 1] + a[n - 2];
  a.resize(n - 2);
  for (auto x : a) t += x;
  std::sort(a.begin(), a.end(), std::greater<LL>());
  for (auto x : a) {
    if (t >= x << 1) t -= x << 1;
  }
  puts(t ? "No" : "Yes");
  return 0;
}