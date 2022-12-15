#include <cstdio>
#include <string>
#include <iostream>

const int N = 100 + 10;

int count(const std::string &s) {
  int res = 0;
  for (int i = 0; i < s.length(); ++i)
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
      ++res;
  return res;
}

int n, p[N];
std::string s[N];

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> p[i];
  for (int i = 0; i <= n; ++i) std::getline(std::cin, s[i]);
  bool ans = true;
  for (int i = 1; i <= n; ++i) if (count(s[i]) != p[i]) ans = false;
  puts(ans ? "YES" : "NO");
  return 0;
}