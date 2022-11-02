#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int l = -1, r = -1;
    while (n--) {
      int tmp;
      scanf("%d", &tmp);
      if (!tmp) {
        r = n;
        if (!~l) l = n;
      }
    }
    if (~l)
      printf("%d\n", l - r + 2);
    else
      printf("%d\n", 0);
  }
  return 0;
}