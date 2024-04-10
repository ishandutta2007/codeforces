#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    bool flg = true;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
      if (a[i] && a[i - 1] >= a[i]) {
        flg = false;
        break;
      } else {
        a[i] += a[i - 1];
      }
    if (!flg) {
      puts("-1");
      continue;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}