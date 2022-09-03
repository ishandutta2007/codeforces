#include <cstdio>

int main() {
  long long a, b;
  int r;
  scanf("%lld%lld", &a, &b);
  for (r = 0; a <= b; r++) {
    a *= 3;
    b *= 2;
  }
  printf("%d\n", r);
}