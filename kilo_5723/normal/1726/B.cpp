#include <cstdio>
#include <iostream>

using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (m < n) {
      puts("No");
      continue;
    }
    if (n & 1) {
      puts("Yes");
      for (int i = 1; i < n; i++) printf("1 ");
      printf("%d\n", m - n + 1);
    } else {
      if (m & 1) {
        puts("No");
        continue;
      }
      puts("Yes");
      for (int i = 2; i < n; i++) printf("1 ");
      printf("%d %d\n", (m - n + 2) / 2, (m - n + 2) / 2);
    }
  }
  return 0;
}