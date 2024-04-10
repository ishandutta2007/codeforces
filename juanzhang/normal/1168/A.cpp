#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n, m, a[maxn];

bool check(int mid) {
  for (int i = 1, lst = -1; i <= n; i++) {
    int v = min(m - 1, a[i] + mid), x = -1;
    if (a[i] + mid >= mid) x = a[i] + mid - m;
    if (v < lst) {
      return 0;
    } else {
      if (lst == -1) {
        lst = ~x ? 0 : a[i];
      } else if (!((a[i] <= lst && lst <= v) || (lst <= x))) {
        lst = max(lst, a[i]);
      }
    }
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  int l = 0, r = m - 1, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  printf("%d", l);
  return 0;
}