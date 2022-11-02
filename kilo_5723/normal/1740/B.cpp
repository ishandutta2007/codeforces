#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> arr;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    int mxm = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      ans += min(a, b);
      mxm = max(mxm, max(a, b));
    }
    printf("%lld\n", (ans + mxm) << 1);
  }
  return 0;
}