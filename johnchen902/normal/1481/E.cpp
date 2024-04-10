#include <algorithm>
#include <stdio.h>

int a[500000];
int left[500000];
int right[500000];
int cnt[500000];
int dp[500001];

int main() {
  int n;
  scanf("%d", &n);
  std::fill_n(left, n, n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;

    left[a[i]] = std::min(left[a[i]], i);
    right[a[i]] = std::max(right[a[i]], i);
    cnt[a[i]] += 1;
  }

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (i == right[a[i]]) {
      dp[i + 1] = std::max(dp[left[a[i]]] + cnt[a[i]], dp[i]);
    } else {
      dp[i + 1] = dp[i];
    }
  }

  int maxcost = 0;
  for (int i = 0; i < n; i++) {
    maxcost = std::max(maxcost, std::max(dp[i + 1], dp[i] + cnt[a[i]]));
    cnt[a[i]]--;
  }

  printf("%d\n", n - maxcost);
}