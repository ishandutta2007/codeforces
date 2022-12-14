#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, k, ans[N];

int main() {
  scanf("%d%d", &n, &k);
  int l = 1, r = n;
  for (int i = 1; i <= k; ++i) if (i & 1) ans[i] = l++; else ans[i] = r--;
  for (int i = k + 1; i <= n; ++i) ans[i] = l++;
  if (!(k & 1)) std::reverse(ans + k + 1, ans + n + 1);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}