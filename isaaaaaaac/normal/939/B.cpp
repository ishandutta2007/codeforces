#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 5005;

int f[N];

int main() {
  LL tot, x;
  int n, ID = 0;
  LL Best = 1e18, cnt = 0;
  scanf("%lld%d", &tot, &n);
  for (int i = 1; i <= n; i ++) {
    scanf("%lld", &x);
    if (tot % x < Best) {
      Best = tot % x;
      ID = i;
      cnt = tot / x;
    }
  }
  printf("%d %lld\n", ID, cnt);
  return 0;
}