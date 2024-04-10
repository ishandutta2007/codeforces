#include <stdio.h>

const int N = 100000 + 10;

int n, m, l[N], r[N], q[N], a[N];

bool solve(int x) {
  static int tag[N];
  for (int i = 1; i <= n; ++i) tag[i] = 0;
  for (int i = 1; i <= m; ++i) {
    if (q[i] >> x & 1) {
      ++tag[l[i]];
      --tag[r[i] + 1];
    }
  }
  for (int i = 1; i <= n; ++i) tag[i] += tag[i - 1];
  for (int i = 1; i <= n; ++i) if (tag[i]) a[i] |= 1 << x;
  static int sum[N];
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (a[i] >> x & 1);
  for (int i = 1; i <= m; ++i) if (!(q[i] >> x & 1) && sum[r[i]] - sum[l[i] - 1] == r[i] - l[i] + 1) return false;
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &l[i], &r[i], &q[i]);
  for (int i = 0; i < 30; ++i) if (!solve(i)) return puts("NO"), 0;
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
  return 0;
}