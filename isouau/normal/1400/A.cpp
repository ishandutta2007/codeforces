#include <bits/stdc++.h>

const int N = 55;

char c[N];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, c + 1);
    for (int i = 1; i <= n; i++) putchar(c[i * 2 - 1]);
    putchar('\n');
  }
  return 0;
}