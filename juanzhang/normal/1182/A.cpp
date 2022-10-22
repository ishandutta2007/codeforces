#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n & 1) {
    return puts("0"), 0;
  }
  long long ans = 1ll << (n >> 1);
  printf("%I64d", ans);
  return 0;
}