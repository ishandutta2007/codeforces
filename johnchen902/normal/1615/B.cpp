#include <stdio.h>
#include <algorithm>

int solve2(int a, int b) {
#if 0
  int ans = 0;
  for (int i = 0; i < a; i++)
    if (((i >> b) & 1) == 0)
      ans++;
  return ans;
#else
  int x = (a >> (b + 1)) << (b + 1);
  return (x >> 1) + std::min(1 << b, a - x);
#endif
}

int solve(int l, int r) {
  int ans = r - l + 1;
  for (int i = 0; (1 << i) < r; i++)
    ans = std::min(ans, solve2(r, i) - solve2(l, i));
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    r++;
    printf("%d\n", solve(l, r));
  }
}