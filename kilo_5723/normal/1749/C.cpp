#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int inf = 1e9;
const int maxn = 105;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    a[n] = inf;
    for (int k = n; k >= 0; k--) {
      bool flg = true;
      for (int i = 0; i < k; i++)
        if (a[k - 1 + i] > i + 1) {
          flg = false;
          break;
        }
      if (flg) {
        printf("%d\n", k);
        break;
      }
    }
  }
  return 0;
}