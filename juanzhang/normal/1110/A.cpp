#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, k, ans = 0;
  scanf("%d %d", &b, &k);
  b = b & 1;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a);
    if (i < k) ans = (ans + ((a & 1) && (b))) % 2;
    else ans = (ans + (a & 1)) % 2;
  }
  puts(ans ? "odd" : "even");
  return 0;
}