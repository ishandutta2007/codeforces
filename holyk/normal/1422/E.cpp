#include <bits/stdc++.h>

using PSS = std::pair<std::string, std::string>;

constexpr int N(1e5 + 5);
int n;
std::string s, ne[N];
PSS ans[N];
int len[N], sta[N];
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> s;
  n = s.length();
  if (n == 1) {
    std::cout << "1 " << s << "\n";
    return 0;
  }
  ans[n - 1] = { s.substr(n - 1), "" };
  len[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (s[i] == s[i + 1]) {
        if (s.substr(i, 1) == ans[i + 2].first.substr(0, 1) ? s.substr(i, 1) > ne[i + 2] : s.substr(i, 1) > ans[i + 2].first) {
          len[i] = len[i + 2];
          ans[i] = ans[i + 2];
          ne[i] = ne[i + 2];
          continue;
        }
    }
    len[i] = len[i + 1] + 1;
    ans[i] = { s[i] + ans[i + 1].first, ans[i + 1].second };
    if (len[i] == 11)
      ans[i] = { ans[i].first.substr(0, 5), ans[i].first.substr(9) };
    else if (len[i] > 11)
      ans[i].first = ans[i].first.substr(0, 5);
    ne[i] = s.substr(i, 1) == ans[i + 1].first.substr(0, 1) ? ne[i + 1] : ans[i + 1].first.substr(0, 1);
  }
  for (int i = 0; i < n; i++) {
    std::cout << len[i] << ' ';
    if (len[i] <= 10) 
      std::cout << ans[i].first << "\n";
    else
      std::cout << ans[i].first << "..." << ans[i].second << "\n";
  }
    
  return 0; 
}