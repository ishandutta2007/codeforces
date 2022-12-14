#include <cstdio>
#include <numeric>
#include <algorithm>

const int N = 3000 + 10;

int m, n, a[N];
char ans[N][N];

inline bool comp(int x, int y) { return a[x] > a[y]; }

bool init() {
  int p = 0, q = 0;
  for (int i = 1; i <= n; ++i) if ((p += a[i]) > (q += 2 * (m - i))) return false;
  for (int i = n + 1; i <= m; ++i) {
    q += 2 * (m - i);
    a[i] = std::min(a[i - 1], q - p);
    p += a[i];
    if (p > q) return false;
  }
  return p == q;
}

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (!init()) return puts("no"), 0;
  for (int i = 1; i <= m; ++i) {
    ans[i][i] = 'X';
    static int b[N];
    for (int j = i + 1; j <= m; ++j) b[j] = j;
    std::sort(b + i + 1, b + m + 1, comp);
    for (int j = m; j > i; --j) {
      int k = b[j];
      if (a[i] >= 2) {
        ans[i][k] = 'W';
        ans[k][i] = 'L';
        a[i] -= 2;
      } else if (a[i] == 1) {
        ans[i][k] = ans[k][i] = 'D';
        --a[i];
        --a[k];
      } else {
        ans[i][k] = 'L';
        ans[k][i] = 'W';
        a[k] -= 2;
      }
    }
  }
  puts("yes");
  for (int i = 1; i <= m; ++i) puts(ans[i] + 1);
  return 0;
}