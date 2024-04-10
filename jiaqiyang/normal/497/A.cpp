#include <iostream>

const int N = 100 + 10;

int n, m;
std::string s[N];

int main() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) std::cin >> s[i];
  int ans = 0;
  static bool flag[N];
  for (int i = 0; i < m; ++i) {
    bool cur = true;
    for (int j = 1; j < n; ++j) {
      if (!flag[j] && s[j][i] > s[j + 1][i]) {
        cur = false;
        break;
      }
    }
    if (cur) {
      for (int j = 1; j < n; ++j) if (s[j][i] < s[j + 1][i]) flag[j] = true;
    } else {
      ++ans;
    }
  }
  std::cout << ans << '\n';
  return 0;
}