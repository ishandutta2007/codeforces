#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      a[t] = i;
    }
    for (int i = 1; i <= n; i++) printf("%d ", min(a[i] + 2, n));
    puts("");
  }
  return 0;
}