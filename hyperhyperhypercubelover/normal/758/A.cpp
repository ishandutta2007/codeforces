#include <cstdio>

int main() {
  int mx = 0, s = 0;
  int i, n, t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    if (t > mx) mx = t;
    s += t;
  }
  printf("%d\n", n * mx - s);
}