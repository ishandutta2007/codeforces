#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (x) swap(x, y);
    if (!y || x || (n - 1) % y) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n - 1; i++) printf("%d ", i - i % y + 2);
    puts("");
  }
  return 0;
}