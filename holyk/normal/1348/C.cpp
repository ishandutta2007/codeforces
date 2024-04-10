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
  int t, n, k;
  std::string s;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k >> s;
    std::sort(s.begin(), s.end());
    if (s[0] != s[k - 1]) {
      std::cout << s[k - 1] << "\n";
      continue; 
    }
    if (s[0] == s.back()) {
      std::cout << s.substr(0, (n + k - 1) / k) << "\n";
      continue;
    }
    std::vector<PII> v;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[j] == s[i]; j++)
        ;
      v.push_back({j - i, s[i]});
    }
    if (v.size() == 2 && v[0].first == k) {
      std::cout << s[0] << s.substr(v[0].first, (v[1].first + k - 1) / k) << "\n";
    } else {
      std::cout << s[0] << s.substr(0, v[0].first - k) << s.substr(v[0].first) << "\n";
    }
 }
  return 0;
}