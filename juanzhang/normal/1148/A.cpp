#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int d = min(a, b);
  printf("%I64d", 2ll * (c + d) + (a - d || b - d));
  return 0;
}