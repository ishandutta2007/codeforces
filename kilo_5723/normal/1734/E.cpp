#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 360;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%lld ", ((a[i] - 1LL * i * i + 1LL * i * j) % n + n) % n);
    puts("");
  }
  return 0;
}