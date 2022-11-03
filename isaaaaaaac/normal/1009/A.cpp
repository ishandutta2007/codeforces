#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 50;

int a[N], b[N], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
  int cnt = 0;
  for (int i = 1, j = 1; i <= n && j <= m; i ++) {
    if (a[i] <= b[j]) j ++, cnt ++;
  }
  printf("%d\n", cnt);
  return 0;
}