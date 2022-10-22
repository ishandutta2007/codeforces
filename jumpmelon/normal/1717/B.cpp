#include <bits/stdc++.h>

using namespace std;

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    int n, k, r, c;
    scanf("%d%d%d%d", &n, &k, &r, &c);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        putchar((i + j) % k == (r + c) % k ? 'X' : '.');
      putchar('\n');
    }
  }
  return 0;
}