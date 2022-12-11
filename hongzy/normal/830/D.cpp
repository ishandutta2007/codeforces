#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 410;
int n, f[N][N];
int main() {
  scanf("%d", &n);
  f[1][0] = f[1][1] = 1;
  rep(i, 2, n) {
    f[i][0] = 1;
    rep(k, 1, n - i + 1) {
      rep(x, 0, k - 1)
        f[i][k] = (f[i][k] + (ll)f[i - 1][x] * f[i - 1][k - 1 - x]) % mod;
      rep(x, 0, k)
        f[i][k] = (f[i][k] + (ll)f[i - 1][x] * f[i - 1][k - x] % mod * (k << 1 | 1)) % mod;
      rep(x, 0, k + 1)
        f[i][k] = (f[i][k] + (ll)f[i - 1][x] * f[i - 1][k + 1 - x] % mod * k * (k + 1)) % mod;
    }
  }
  printf("%d\n", f[n][1]);
  return 0;
}