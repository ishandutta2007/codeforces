#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
      if (n == 3) {
        puts("-1");
        continue;
      }
      for (int i = 4; i <= n; i++) printf("%d ", i);
      puts("1 2 3");
    } else {
      for (int i = 1; i <= n; i += 2) printf("%d %d ", i + 1, i);
      puts("");
    }
  }

  return 0;
}