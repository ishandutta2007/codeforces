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
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0;
    int l = 0, r = n;
    while (l < r) {
      while (l < n && a[l] == 0) l++;
      while (r && a[r - 1] == 1) r--;
      if (l >= r) break;
      ans++;
      l++;
      r--;
    }
    printf("%d\n",ans);
  }
  return 0;
}