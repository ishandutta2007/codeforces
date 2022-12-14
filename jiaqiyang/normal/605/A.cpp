#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, val[N], pos[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &val[i]), pos[val[i]] = i;
  if (n == 1) return puts("0"), 0;
  static int pre[N], suf[N];
  for (int i = 1; i <= n; ++i) pre[i] = (pos[i] > pos[i - 1] ? pre[i - 1] : 0) + 1;
  for (int i = n; i > 0; --i) suf[i] = (pos[i] < pos[i + 1] ? suf[i + 1] : 0) + 1;
  int ans = n - std::max(pre[n], suf[1]);
  for (int i = 1; i < n; ++i) if (pos[i] < pos[i + 1]) ans = std::min(ans, n - pre[i] - suf[i + 1]);
  printf("%d\n", ans);
  return 0;
}