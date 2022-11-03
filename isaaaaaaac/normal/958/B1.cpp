#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1005;

int deg[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i ++) {
    scanf("%d%d", &x, &y);
    deg[x] ++; deg[y] ++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i ++) ans += deg[i] == 1;
  printf("%d\n", ans);
  return 0;
}