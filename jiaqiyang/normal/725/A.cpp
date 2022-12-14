#include <cstdio>

const int N = 200000 + 10;

int n;
char s[N];

int main() {
  scanf("%d %s", &n, s + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (s[i] == '<') ++ans; else break;
  for (int i = n; i > 0; --i) if (s[i] == '>') ++ans; else break;
  printf("%d\n", ans);
  return 0;
}