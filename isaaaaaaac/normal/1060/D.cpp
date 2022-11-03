#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 50;

int l[N], r[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d%d", &l[i], &r[i]);
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);
  long long ans = n;
  for (int i = 1; i <= n; i ++)
    ans += max(l[i], r[i]);
  printf("%lld\n", ans);
  return 0;
}