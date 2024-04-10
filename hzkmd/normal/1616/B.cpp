#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int p = 0;
    while (p + 1 < n && s[p + 1] <= s[p]) {
      ++p;
    }
    if (p == 0 || s[0] == s[1]) {
      std::cout << s[0] << s[0] << "\n";
    } else {
      for (int i = 0; i <= p; ++i) {
        std::cout << s[i];
      }
      for (int i = p; i >= 0; --i) {
        std::cout << s[i];
      }
      std::cout << "\n";
    }
  }
}