#include <cstdio>

int t, h, d;

int check(int a, int b) {
  return (a % 10 != b % 10) + (a / 10 != b / 10);
}

int main() {
  scanf("%d%d:%d", &t, &h, &d);
  int l, r;
  if (t == 12) l = 1, r = 12; else l = 0, r = 23;
  int x = 1, y = 0;
  for (int i = l; i <= r; ++i)
    for (int j = 0; j < 60; ++j)
      if (check(i, h) + check(j, d) < check(x, h) + check(y, d)) x = i, y = j;
  printf("%02d:%02d\n", x, y);
  return 0;
}