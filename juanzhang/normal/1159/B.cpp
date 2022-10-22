#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, top, a[maxn], st[maxn], lef[maxn], rig[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int ans = 1 << 30;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, a[i] / max(i - 1, n - i));
  }
  printf("%d", ans);
  return 0;
}