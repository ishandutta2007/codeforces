#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 50;

int n, h;
int l[N], r[N], sum[N], ans;

inline void check(int i) {
  int L = i, R = n, mid;
  while (L <= R) {
    mid = (L + R) >> 1;
    if (r[mid] - l[i] - (sum[mid] - sum[i - 1]) < h) {
      L = mid + 1;
      int hh = h - (r[mid] - l[i] - (sum[mid] - sum[i - 1]));
      ans = max(ans, r[mid] - l[i] + min(hh, l[mid + 1] - r[mid]));
    }
    else R = mid - 1;
  }
}

int main() {
  scanf("%d%d", &n, &h);
  for (int i = 1; i <= n; i ++) {
    scanf("%d%d", &l[i], &r[i]);
    sum[i] = sum[i - 1] + r[i] - l[i];
  }
  l[n + 1] = 2e9 + 500;
  for (int i = 1; i <= n; i ++) check(i);
  printf("%d\n", ans);
  return 0;
}