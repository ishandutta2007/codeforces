#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

char s[N];

int main() {
  scanf(" %s", s);
  bool flag = false;
  for (char *i = s; *i; ++i) {
    if (*i != 'a') {
      for (; *i && *i != 'a'; ++i) *i = (*i - 'a' + 25) % 26 + 'a';
      flag = true;
      break;
    }
  }
  if (!flag) s[strlen(s) - 1] = 'z';
  puts(s);
  return 0;
}