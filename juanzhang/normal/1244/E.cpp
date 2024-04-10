#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;
int n, k, a[maxn], s1[maxn], s2[maxn];

bool check(int mid) {
  int l = 1, r = 0;
  for (; l <= n; l++) {
    while (r < n && a[r + 1] <= a[l] + mid) r++;
    int val = a[l] * (l - 1) - s1[l - 1] + s2[r + 1] - (a[l] + mid) * (n - r);
    if (val <= k) return 1;
  }
  for (int l = n + 1, r = n; r; r--) {
    while (l > 1 && a[l - 1] >= a[r] - mid) l--;
    int val = (a[r] - mid) * (l - 1) - s1[l - 1] + s2[r + 1] - a[r] * (n - r);
    if (val <= k) return 1;
  }
  return 0;
}

signed main() {
  scanf("%I64d %I64d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    s1[i] = s1[i - 1] + a[i];
  }
  for (int i = n; i; i--) {
    s2[i] = s2[i + 1] + a[i];
  }
  int l = 0, r = 1e9, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  printf("%I64d", l);
  return 0;
}