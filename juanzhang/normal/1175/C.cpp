#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, k, a[maxn], d[maxn];

void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int val = INT_MAX, ans; k++;
  for (int i = k; i <= n; i++) {
    int x = a[(i + i - k + 1) / 2];
    int tmp = max(x - a[i - k + 1], a[i] - x);
    if (val > tmp) {
      val = tmp, ans = x;
    }
    x = (a[i] + a[i - k + 1]) / 2;
    tmp = max(x - a[i - k + 1], a[i] - x);
    if (val > tmp) {
      val = tmp, ans = x;
    }
  }
  printf("%d\n", ans);
}

int main() {
  int Tests;
  scanf("%d", &Tests);
  while (Tests--) solve();
  return 0;
}