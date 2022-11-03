#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 3e5 + 5;

LL f[N], a[N];

int main() {
  int n, s, t;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++)
    scanf("%lld", &a[i]);
  scanf("%d%d", &s, &t);
  for (int i = 1; i <= n; i ++) {
    f[n + s - i + 1] += a[i];
    f[n + t - i + 1] -= a[i];
  }
  for (int i = 1; i <= n + n; i ++) {
    f[i] += f[i - 1];
    if (i > n) f[i - n] += f[i];
  }
  int id = n;
  for (int i = n - 1; i >= 1; i --)
    if (f[i] >= f[id]) id = i;
  printf("%d\n", id);
  return 0;
}