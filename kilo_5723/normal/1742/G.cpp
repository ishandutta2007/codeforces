#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sort(a + i, a + n, [sum](int a, int b) { return (sum | a) > (sum | b); });
      if ((sum | a[i]) == sum) break;
      sum |= a[i];
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}