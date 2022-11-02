#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e3 + 5;
int a[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i < n; i += 2) a[i] = ++m;
    for (int i = 0; i < n; i += 2) a[i] = ++m;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}