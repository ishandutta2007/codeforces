#include <bits/stdc++.h>

using namespace std;

typedef long long big;

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    big n;
    scanf("%lld", &n);
    printf("%lld\n", n + (n / 2 + n / 3) * 2);
  }
  return 0;
}