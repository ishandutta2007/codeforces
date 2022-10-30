#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int mx = 0, mn = 1e9;
    while (n--) {
      int t;
      scanf("%d", &t);
      mx = max(mx, t);
      mn = min(mn, t);
    }
    printf("%d\n",mx-mn);
  }
  return 0;
}