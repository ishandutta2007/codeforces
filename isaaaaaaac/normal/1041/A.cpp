#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i < n; i ++)
    ans += a[i + 1] - a[i] - 1;
  printf("%d\n", ans);
  return 0;
}