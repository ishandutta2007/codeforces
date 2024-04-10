// Hydro submission #62fc2b5ae42c71bad9ecb73f@1660693339539
#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[105];
int main() {
  scanf("%d", &t);
  while (t--) {
  scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) printf("%d ",  a[i]);
    printf("\n");
    swap(a[1], a[n]);
    for (int i = 1; i <= n - 1; i++) {
      for (int i = 1; i <= n; i++) printf("%d ",  a[i]);
      swap(a[n - i], a[n - i + 1]);
      printf("\n");
    }
  }
  return 0;
}