#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 5;

int n, c, a[N], que[N], fr = 1, re = 1;
LL dp[N], sum[N];

int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; i ++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i ++) {
    while (que[fr] < i - c + 1 && fr < re) fr ++;
    while (a[que[re - 1]] >= a[i] && fr < re) re --;
    que[re ++] = i;
    dp[i] = dp[i - 1] + a[i];
    sum[i] = sum[i - 1] + a[i];
    if (i >= c) dp[i] = min(dp[i], dp[i - c] + sum[i] - sum[i - c] - a[que[fr]]);
  }
  printf("%lld\n", dp[n]);
  return 0;
}