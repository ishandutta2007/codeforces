#include <algorithm>
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
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    puts(unique(a, a + n) - a == n ? "YES" : "NO");
  }
  return 0;
}