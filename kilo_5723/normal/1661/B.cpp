#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 32768;
int dp[mod];
int que[mod];
int main() {
  fill(dp, dp + mod, -1);
  int l = 0, r = 0;
  dp[0] = 0;
  que[r++] = 0;
  while (l < r) {
    int u = que[l++];
    vector<int> arr;
    arr.push_back((u + mod - 1) % mod);
    if (!(u & 1)) {
      arr.push_back(u >> 1);
      arr.push_back((u >> 1) + mod / 2);
    }
    for (auto v : arr)
      if (!~dp[v]) {
        dp[v] = dp[u] + 1;
        que[r++] = v;
      }
  }
  int n;
  scanf("%d", &n);
  while (n--) {
    int t;
    scanf("%d", &t);
    printf("%d ", dp[t]);
  }
  puts("");
  return 0;
}