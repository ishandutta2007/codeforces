#include <map>
#include <string>
#include <iostream>

const int N = 1000 + 10;

int n;
std::string a[N], b[N], s[N];

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i] >> b[i];
    a[i] = a[i].substr(0, 3);
    b[i] = a[i].substr(0, 2) + b[i][0];
  }
  std::map<std::string, int> cnt;
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  for (int i = 1; i <= n; ++i) if (cnt[a[i]] > 1) s[i] = b[i];
  cnt.clear();
  for (int i = 1; i <= n; ++i) if (!s[i].empty()) ++cnt[s[i]];
  while (1) {
    bool flag = false;
    for (int i = 1; i <= n; ++i) if (s[i].empty() && cnt[a[i]]) ++cnt[s[i] = b[i]], flag = true;
    for (auto it : cnt) {
      if (it.second > 1) {
        std::cout << "NO\n";
        return 0;
      }
    }
    if (!flag) {
      for (int i = 1; i <= n; ++i) if (s[i].empty()) s[i] = a[i];
      break;
    }
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; ++i) std::cout << s[i] << '\n';
  return 0;
}