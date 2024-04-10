#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  int p = s.find('1');
  s.erase(0, p);
  n = s.size();
  if (n == 0) {
    std::cout << 0 << "\n";
    return 0;
  }

  auto cmp = [&](int i, int j) {
    for (int k = std::min(n - i, n - j); k < n; ++k) {
      int a = k < n - i ? 0 : s[k - n + i] - '0';
      int b = k < n - j ? 0 : s[k - n + j] - '0';
      a |= s[k] - '0';
      b |= s[k] - '0';
      if (a != b) {
        return a < b;
      }
    }
    return false;
  };

  int max = 1;
  for (int i = 2; i <= n; ++i) {
    if (cmp(max, i)) {
      max = i;
    }
  }
  for (int k = 0; k < n; ++k) {
    int a = k < n - max ? 0 : s[k - n + max] - '0';
    a |= s[k] - '0';
    std::cout << a;
  }
  std::cout << "\n";
}