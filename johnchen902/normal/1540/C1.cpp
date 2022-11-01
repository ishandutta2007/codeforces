#include <stdio.h>
#include <algorithm>
#include <numeric>

constexpr int mod = 1'000'000'007;

int c[100], b[99], bb[99];

// int a[100];
//
// bool test(int n, int x) {
//   if (a[0] < x) return false;
//   if (a[0] + a[1] < 2 * x + b[0]) return false;
//   if (a[0] + a[1] + a[2] < 3 * x + b[0] * 2 + b[1]) return false;
//   return true;
// }
// 
// int solve(int n, int x) {
//   int ans = 0;
//   for (a[0] = 0; a[0] <= c[0]; a[0]++)
//     for (a[1] = 0; a[1] <= c[1]; a[1]++)
//       for (a[2] = 0; a[2] <= c[2]; a[2]++)
//         if (test(n, x))
//           ans++;
//   return ans;
// }

int dp[100][10001];

int solve(int n, int x) {
  for (int i = 0; i <= c[0]; i++)
    dp[0][i] = i >= x ? 1 : 0;

  int sum = c[0];
  for (int i = 1; i < n; sum += c[i], i++) {
    std::fill_n(dp[i], sum + c[i] + 1, 0);
    for (int jk = std::max(0, (i + 1) * x + bb[i - 1]); jk <= sum + c[i]; jk++) { 
      long long dpsum = 0;
      for (int j = 0; j <= sum; j++) {
        int k = jk - j;
        if (k >= 0 && k <= c[i])
          dpsum += dp[i - 1][j];
      }
      dp[i][jk] = dpsum % mod;
    }
  }

  return std::accumulate(dp[n - 1], dp[n - 1] + sum + 1, 0LL) % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", c + i);
  for (int i = 0; i < n - 1; i++)
    scanf("%d", b + i);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j <= i; j++)
      bb[i] += b[j] * (i - j + 1);

  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", solve(n, x));
  }
}