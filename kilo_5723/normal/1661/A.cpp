#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50;
ll a[maxn], b[maxn], dp[maxn][2];
int _abs(int n) { return n < 0 ? -n : n; }
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        dp[i][j] = min(
            dp[i - 1][j] + _abs(a[i] - a[i - 1]) + _abs(b[i] - b[i - 1]),
            dp[i - 1][j ^ 1] + _abs(a[i] - b[i - 1]) + _abs(b[i] - a[i - 1]));
      }
    }
    printf("%lld\n", dp[n - 1][0]);
  }
  return 0;
}