#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, a[maxn];

map <int, int> mp;

bool check(int l, int r) {
  int x = a[l + 1] - a[l];
  for (int i = l + 1; i < r; i++) {
    if (a[i + 1] != a[i] + x) {
      return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i), mp[a[i]] = i;
  }
  if (n < 3) {
    return puts("1"), 0;
  }
  sort(a + 1, a + n + 1);
  if (check(2, n)) {
    return printf("%d", mp[a[1]]), 0;
  }
  if (check(1, n - 1)) {
    return printf("%d", mp[a[n]]), 0;
  }
  int pos = 0;
  int d = (a[n] - a[1]) / (n - 2);
  for (int i = 1; i < n; i++) {
    if (a[i + 1] - a[i] == d) continue;
    if (a[i + 2] - a[i] == d && !pos) {
      pos = i + 1, i++;
    } else {
      return puts("-1"), 0;
    }
  }
  printf("%d", mp[a[pos]]);
  return 0;
}