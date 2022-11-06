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


int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t, n; std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a;
    for (int i = 0, j; i < n; i = j) {
      j = i;
      while (j < n && s[j] == s[i]) j++;
      a.push_back(j - i);
    }
    n = a.size();
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < i) j++;
      while (j < n && a[j] == 1) j++;
      if (j < n) a[j]--;
      else n--;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}