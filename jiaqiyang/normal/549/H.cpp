#include <cmath>
#include <cstdio>

const long double eps = 1e-15;

int a, b, c, d;

inline long double min(long double a, long double b, long double c, long double d) {
  if (b < a) a = b;
  if (c < a) a = c;
  if (d < a) a = d;
  return a;
}

inline long double max(long double a, long double b, long double c, long double d) {
  if (b > a) a = b;
  if (c > a) a = c;
  if (d > a) a = d;
  return a;
}

bool Check(long double gap) {
  long double u = min((a - gap) * (d - gap), (a - gap) * (d + gap), (a + gap) * (d - gap), (a + gap) * (d + gap));
  long double v = max((a - gap) * (d - gap), (a - gap) * (d + gap), (a + gap) * (d - gap), (a + gap) * (d + gap));
  long double x = min((b - gap) * (c - gap), (b - gap) * (c + gap), (b + gap) * (c - gap), (b + gap) * (c + gap));
  long double y = max((b - gap) * (c - gap), (b - gap) * (c + gap), (b + gap) * (c - gap), (b + gap) * (c + gap));
  return !(v < x || y < u);
}

int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  long double l = 0.0, r = 1e10;
  for (int cnt = 80; cnt--;) {
    long double mid = (l + r) / 2.0;
    if (Check(mid)) r = mid; else l = mid;
  }
  printf("%.15f\n", (double)l);
  return 0;
}