#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100005;

int a[N], p, n, suf[N];

int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = n; i >= 1; i --)
    suf[i] = (suf[i + 1] + a[i]) % p;
  int cur = 0, ans = 0;
  for (int i = 1; i < n; i ++) {
    cur = (cur + a[i]) % p;
    ans = max(ans, cur + suf[i + 1]);
  }
  printf("%d\n", ans);
  return 0;
}