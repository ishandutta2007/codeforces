#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 105;
int cnt[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &cnt[i]);
      sum += cnt[i];
    }
    int p = 0;
    for (int i = 1; i < n; i++)
      if (cnt[i] > cnt[p]) p = i;
    printf("%d\n", p + 1);
  }
  return 0;
}