#include <stdio.h>

char s[101];

int solve(int n, int a, int b) {
  if (b >= 0)
    return n * (a + b);

  int c = 0;
  for (int i = 0; i + 1 < n; i++)
    if (s[i] != s[i + 1])
      c++;

  return n * a + (c + 3) / 2 * b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b;
    scanf("%d%d%d%s", &n, &a, &b, s);
    printf("%d\n", solve(n, a, b));
  }
}