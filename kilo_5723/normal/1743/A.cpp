#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
    }
    printf("%d\n", 6 * (10 - n) * (9 - n) / 2);
  }
  return 0;
}