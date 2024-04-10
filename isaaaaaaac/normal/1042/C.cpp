#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 50;

int a[N], del[N];

int main() {
  int n, z = 0, f = 0, pos = 0;
  a[0] = - 2e9;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%d", &a[i]);
    z += (a[i] == 0);
    f += (a[i] < 0);
    if (a[i] < 0 && a[i] > a[pos]) pos = i;
  }
  if (f & 1) del[pos] = 1;
  for (int i = 1; i <= n; i ++)
    if (!a[i]) del[i] = 1;
  int lst = 0, ok = 0, tot = 0;
  for (int i = 1; i <= n; i ++) {
    if (del[i]) {
      if (lst) printf("1 %d %d\n", lst, i), tot ++;
      lst = i;
    }
    else {
      if (ok) printf("1 %d %d\n", ok, i), tot ++;
      ok = i;
    }
  }
  if (ok && lst) printf("2 %d\n", lst);
  return 0;
}