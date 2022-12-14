#include <cstdio>

const int N = 200000 + 10;

int n, p[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ans ^= x;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    static bool flag[N];
    if (flag[i]) continue;
    ++cnt;
    for (int j = i; !flag[j]; j = p[j]) flag[j] = true;
  }
  if (cnt > 1) ans += cnt;
  printf("%d\n", ans);
  return 0;
}