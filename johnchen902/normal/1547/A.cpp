#include <stdio.h>
#include <math.h>

int solve() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

  int ans = abs(x1 - x2) + abs(y1 - y2);

  if ((x1 == x2 && x2 == x3 && y3 > std::min(y1, y2) && y3 < std::max(y1, y2)) ||
      (y1 == y2 && y2 == y3 && x3 > std::min(x1, x2) && x3 < std::max(x1, x2))) {
    ans += 2;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--)
    printf("%d\n", solve());
}