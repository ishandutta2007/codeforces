#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
vector<int> e[maxn];
pii dp[maxn][2];
vector<int> sel[maxn];
bool cmp(pii a, pii b) {
  if (a.first != b.first) return a.first > b.first;
  if (a.second != b.second) return a.second < b.second;
  return false;
}
pii operator+(pii a, pii b) {
  return pii(a.first + b.first, a.second + b.second);
}
void dfs(int u, int f) {
  dp[u][0] = pii(0, 1);
  dp[u][1] = pii(1, e[u].size());
  for (auto v : e[u])
    if (v == f) {
      sel[u].push_back(-1);
    } else {
      dfs(v, u);
      dp[u][1] = dp[u][1] + dp[v][0];
      int b = cmp(dp[v][1], dp[v][0]);
      // printf("%d %d, ",dp[])
      dp[u][0] = dp[u][0] + dp[v][b];
      // printf("%d %d %d %d\n",dp[u][0].first,dp[u][0].second,dp[v][b].first,dp[v][b].second);
      sel[u].push_back(b);
      // printf("%d %d %d: %d %d %d %d\n",u,v,b,dp[u][0].first,dp[u][0].second,dp[u][1].first,dp[u][1].second);
    }
}
int arr[maxn];
void write(int u, int f, int b) {
  // puts("1");
  arr[u] = b;
  if (b) {
    for (auto v : e[u])
      if (v != f) write(v, u, 0);
  } else {
    for (int i = 0; i < e[u].size(); i++)
      if (e[u][i] != f) write(e[u][i], u, sel[u][i]);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  if (n == 2) {
    puts("2 2");
    puts("1 1");
    return 0;
  }
  dfs(1, 1);
  int b = cmp(dp[1][1], dp[1][0]);
  // for (int i = 1; i <= n; i++) {
  //   printf("%d\n", i);
  //   printf("%d %d\n", dp[i][0].first, dp[i][0].second);
  //   printf("%d %d\n", dp[i][1].first, dp[i][1].second);
  // }
  printf("%d %d\n", dp[1][b].first, dp[1][b].second);
  write(1, 1, b);
  for (int i = 1; i <= n; i++)
    printf("%d%c", arr[i] ? e[i].size() : 1, i < n ? ' ' : '\n');
  return 0;
}