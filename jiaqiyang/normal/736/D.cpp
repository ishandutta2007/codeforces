#include <cstdio>
#include <bitset>

const int N = 2000 + 10, M = 500000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m, x[M], y[M];
std::bitset<2 * N> a[N];

int main() {
  n = nextInt();
  m = nextInt();
  for (int i = 1; i <= m; ++i) {
    x[i] = nextInt();
    y[i] = nextInt();
    a[x[i]].flip(y[i]);
  }
  for (int i = 1; i <= n; ++i) a[i][i + N] = 1;
  static int pivot[N];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) if (a[i][j] && pivot[j]) a[i] ^= a[pivot[j]];
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] && !pivot[j]) {
        pivot[j] = i;
        break;
      }
    }
  }
  for (int i = n; i > 0; --i)
    for (int j = i + 1; j <= n; ++j)
      if (a[pivot[i]][j]) a[pivot[i]] ^= a[pivot[j]];
  for (int i = 1; i <= m; ++i) puts(a[pivot[y[i]]][x[i] + N] ? "NO" : "YES");
  return 0;
}