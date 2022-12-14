#include <cstdio>
#include <cmath>
#include <algorithm>

typedef std::pair<int, int> point;

#define x first
#define y second

inline int abs(int a) { return a > 0 ? a : -a; }

point a, b;

int main() {
  scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
  int detx = abs(a.x - b.x), dety = abs(a.y - b.y);
  if (detx && dety && detx != dety) {
    puts("-1");
  } else {
    int det = detx ? detx : dety;
    if (!detx) {
      printf("%d %d %d %d\n", a.x + det, a.y, b.x + det, b.y);
    } else if (!dety) {
      printf("%d %d %d %d\n", a.x, a.y + det, b.x, b.y + det);
    } else {
      point c(std::min(a.x, b.x), std::min(a.y, b.y));
      point d(std::max(a.x, b.x), std::max(a.y, b.y));
      if ((c == a && d == b) || (c == b && d == a)) std::swap(c.x, d.x);
      printf("%d %d %d %d\n", c.x, c.y, d.x, d.y);
    }
  }
  return 0;
}