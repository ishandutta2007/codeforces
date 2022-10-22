#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, ans = 0;
  scanf("%d", &x);
  for (; x; x >>= 3) {
    ans += (x & 7) == 1;
  }
  printf("%d", ans);
  return 0;
}