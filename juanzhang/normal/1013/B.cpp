#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n, val, a[maxn], c[maxn];

int main() {
  scanf("%d %d", &n, &val);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (c[a[i]]) return puts("0"), 0;
    c[a[i]] = 1;
  }
  int ans = 3;
  for (int i = 1; i <= n; i++) {
    if (c[a[i] & val] && (a[i] & val) != a[i]) {
      ans = min(ans, c[a[i] & val]);
    }
    if (!c[a[i] & val]) {
      c[a[i] & val] = 2;
    }
  }
  printf("%d", ans < 3 ? ans : -1);
  return 0;
}