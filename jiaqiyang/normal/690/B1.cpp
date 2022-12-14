#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 50 + 10;

int n;
char s[N][N];

inline void no() {
  puts("No");
  exit(0);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf(" %c", &s[j][n - i + 1]);
  int l = n + 1, r = 0, p = n + 1, q = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      s[i][j] -= '0';
      if (s[i][j] == 4) {
        l = std::min(l, i);
        r = std::max(r, i);
        p = std::min(p, j);
        q = std::max(q, j);
      }
    }
  }
  if (l > r || p > q) no();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int cnt = 0;
      for (int a = -1; a <= 0; ++a)
        for (int b = -1; b <= 0; ++b)
          if (l - 1 <= i + a && i + a <= r && p - 1 <= j + b && j + b <= q) ++cnt;
      if (cnt != s[i][j]) no();
    }
  }
  puts("Yes");
  return 0;
}