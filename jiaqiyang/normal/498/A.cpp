#include <cstdio>

typedef long long i64;

const int N = 300 + 10;

int x1, y1, x2, y2;
int n;

int main() {
  scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n);
  int ans = 0;
  while (n--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    i64 p = (i64)a * x1 + (i64)b * y1 + c, q = (i64)a * x2 + (i64)b * y2 + c;
    if ((p > 0) != (q > 0)) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}