#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> e[maxn];
int a[maxn];
int dp[maxn][2];
void dfs(int u) {
  int sum = 0, mxm = 0;
  dp[u][0] = 0;
  dp[u][1] = 1;
  for (auto v : e[u]) {
    dfs(v);
    dp[u][0] += max(dp[v][0], dp[v][1]);
    dp[u][1] = max(dp[u][1], dp[v][1] + 1);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int t;
    scanf("%d", &t);
    e[t].push_back(i + 1);
  }
  dfs(1);
  printf("%d\n", max(dp[1][0], dp[1][1]));

  return 0;
}