#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 10000 + 10;

int n;
std::vector<int> adj[N];

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int t = adj[i].size();
    ans += t * (t - 1) / 2;
  }
  printf("%d\n", ans);
  return 0;
}