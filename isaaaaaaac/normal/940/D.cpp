#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];
char s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  int r = 1e9, l = - 1e9;
  for (int i = 5; i <= n; i ++) {
    if (s[i] != s[i - 1]) {
      if (s[i] == '0') {
        for (int j = i - 4; j <= i; j ++) r = min(r, a[j] - 1);
      }
      else {
        for (int j = i - 4; j <= i; j ++) l = max(l, a[j] + 1);
      }
    }
    // else {
    //   if (s[i] == '0')
    // }
  }
  printf("%d %d\n", l, r);
  return 0;
}