#include <cstdio>

int main() {
  puts("YES");
  int n;
  for (scanf("%d", &n); n--;) {
    int x, y;
    scanf("%d%d%*d%*d", &x, &y);
    printf("%d\n", ((x & 1) << 1 | (y & 1)) + 1);
  }
  return 0;
}