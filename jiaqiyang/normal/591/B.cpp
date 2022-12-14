#include <cstdio>

const int N = 200000 + 10;

int n, m;
char s[N], trans[N];

int main() {
  scanf("%d%d %s", &n, &m, s);
  for (int i = 'a'; i <= 'z'; ++i) trans[i] = i;
  while (m--) {
    char x, y;
    scanf(" %c %c", &x, &y);
    if (x == y) continue;
    static char cur[N];
    for (int i = 'a'; i <= 'z'; ++i) cur[i] = i;
    cur[x] = y;
    cur[y] = x;
    for (int i = 'a'; i <= 'z'; ++i) trans[i] = cur[trans[i]];
  }
  for (char *i = s; *i != '\0'; ++i) putchar(trans[*i]);
  putchar('\n');
  return 0;
}