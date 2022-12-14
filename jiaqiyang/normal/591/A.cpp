#include <cstdio>

int l, p, q;

int main() {
  scanf("%d%d%d", &l, &p, &q);
  double t = (double)l / (p + q);
  printf("%.10f\n", p * t);
  return 0;
}