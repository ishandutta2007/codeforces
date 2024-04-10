#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] <= p) {
        b[i] = 1;
      } else if (p < q) {
        b[i] = 1;
        p++;
      } else {
        b[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) printf("%d", b[i]);
    puts("");
  }
  return 0;
}