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
  int n; std::string s;
  std::cin >> n >> s;
  int ans = 0;
  for (char c = 'z'; c > 'a'; c--) {
    for (int i = 0; i < n; i++) {
      if (s[i] != c) continue;
      if (i && s[i - 1] == c - 1 || i < n && s[i + 1] == c - 1)
        s.erase(i--, 1), n--, ans++;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != c) continue;
      if (i && s[i - 1] == c - 1 || i < n && s[i + 1] == c - 1)
        s.erase(i, 1), n--, ans++;
    }
  }
  std::cout << ans;
  return 0;
}