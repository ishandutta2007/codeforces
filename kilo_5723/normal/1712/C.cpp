#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    fill(b, b + n + 1, 0);
    fill(c, c + n + 1, 0);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[a[i]] = i;
    }
    int p = n - 1;
    while (p && a[p - 1] <= a[p]) p--;
    for (int i = 0; i < p; i++) p = max(p, b[a[i]]);
    int cnt = 0;
    for (int i = 0; i < p; i++)
      if (!c[a[i]]) {
        c[a[i]] = true;
        cnt++;
      }
    printf("%d\n", cnt);
  }
  return 0;
}