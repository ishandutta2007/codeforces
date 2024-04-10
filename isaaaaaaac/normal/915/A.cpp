#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int main() {
  int n, k, ans = 100000, x;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &x);
    if (k % x == 0) ans = min(ans, k / x);
  }
  printf("%d\n", ans);
  return 0;
}