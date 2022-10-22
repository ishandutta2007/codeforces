#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn], c[maxn];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      c[a[i] + a[j]]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= 200000; i++) {
    ans = max(ans, c[i]);
  }
  printf("%d", ans);
  return 0;
}