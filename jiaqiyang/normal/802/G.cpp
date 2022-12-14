#include <cstdio>
#include <cstring>

char s[1010];

int main() {
  scanf(" %s", s);
  char *p = s;
  const char t[] = "heidi";
  for (int i = 0; i < 5; ++i) if (!(p = strchr(p, t[i]))) return puts("NO"), 0;
  puts("YES");
  return 0;
}