#include <cstdio>

char s[512];

int cnt[26];

int main() {
  scanf(" %s", s);
  int cur = 'a' - 1;
  for (char *i = s; *i; ++i) {
    if (*i <= cur) continue;
    if (*i != cur + 1) return puts("NO"), 0;
    ++cur;
  }
  puts("YES");
  return 0;
}