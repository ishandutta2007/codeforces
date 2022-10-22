#include <bits/stdc++.h>
using namespace std;

int ans[] = {0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int f(int x) {
  int res = 0;
  for (int i = 1; i < x; i++) {
    res = max(res, __gcd(x ^ i, x & i));
  }
  return res;
}

int main() {
//  for (int i = 2; i < 32; i++) {
//    printf("%d:%d\n", i, f(i));
//  }
//  for (int i = 2; i < 26; i++) {
//    printf("%d,", f((1 << i) - 1));
//  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    int pos = 0;
    while ((1 << pos) - 1 < x) pos++;
    if (x == (1 << pos) - 1) {
      printf("%d\n", ans[pos]);
    } else {
      printf("%d\n", (1 << pos) - 1);
    }
  }
  return 0;
}