#include <cstdio>

int x;
char s[10];

int main() {
  scanf("%d of %s", &x, s);
  if (s[0] == 'w') {
    int ans = 0;
    for (int i = 1; i <= 366; ++i)
      if ((i + 3) % 7 == x - 1) ++ans;
    printf("%d\n", ans);
  } else {
    if (x <= 29) puts("12"); else if (x <= 30) puts("11"); else puts("7");
  }
  return 0;
}