#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mx = 0;
    ll sum = 0;
    while (n--) {
      int tmp;
      scanf("%d", &tmp);
      mx = max(mx, tmp);
      sum += tmp;
    }
    if (mx)
      printf("%lld\n", max(1LL, 2 * mx - sum));
    else
      puts("0");
  }
  return 0;
}