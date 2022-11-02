#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    if (l / a == r / a) {
      printf("%d\n", r / a + r % a);
      continue;
    }
    if (r % a == a - 1) {
      printf("%d\n", r / a + r % a);
      continue;
    }
    printf("%d\n", r / a + a - 2);
  }
  return 0;
}