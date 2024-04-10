#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 5;
const ll inf = 1e18;
char s[maxn], t[maxn];
int a[maxn];
ll dp[maxn][maxn][2];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    ll x, y;
    scanf("%d%lld%lld", &n, &x, &y);
    scanf("%s", s);
    scanf("%s", t);
    int sum = 0;
    for (int i = 0; i < n; i++) sum += (a[i] = s[i] ^ t[i]);
    if (sum & 1) {
      puts("-1");
      continue;
    }
    if (x >= y) {
      if (sum != 2) {
        printf("%lld\n", sum / 2 * y);
        continue;
      }
      bool flg = false;
      for (int i = 1; i < n; i++)
        if (a[i] && a[i - 1]) flg = true;
      if (flg)
        printf("%lld\n", min(x, 2 * y));
      else
        printf("%lld\n", y);
      continue;
    }
    int las = -1;
    vector<int> arr;
    for (int i = 0; i < n; i++)
      if (a[i]) {
        if (~las) arr.push_back(i - las);
        las = i;
      }
    // for (auto v : arr) cout << v << ' ';
    // cout << endl;
    int m = arr.size();
    for (int i = 0; i <= m; i++) fill(dp[i][0], dp[i][m + 1], inf);
    dp[0][0][0] = 0;
    for (int i = 1; i <= m; i++)
      for (int j = 0; j <= i; j++) {
        dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
        if (j) dp[i][j][1] = dp[i - 1][j - 1][0] + arr[i - 1] * x;
      }
    ll ans = inf;
    for (int i = 0; i <= m; i++)
      ans = min(ans, min(dp[m][i][0], dp[m][i][1]) + (sum - 2 * i) / 2 * y);
    printf("%lld\n", ans);
    // cout<<endl;
  }
  return 0;
}