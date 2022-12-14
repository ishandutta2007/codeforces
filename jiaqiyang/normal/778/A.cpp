#include <cstdio>
#include <cstring>

const int N = 200000 + 10;

int n, m, a[N];
char s[N], t[N];

bool solve(int tot) {
  static bool flag[N];
  memset(flag, 0, sizeof flag);
  for (int i = 1; i <= tot; ++i) flag[a[i]] = true;
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && (flag[j] || s[j] != t[i])) ++j;
    if (j > n) return false;
    ++j;
  }
  return true;
}

int main() {
  scanf(" %s %s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (solve(mid)) l = mid; else r = mid - 1;
  }
  printf("%d\n", l);
  return 0;
}