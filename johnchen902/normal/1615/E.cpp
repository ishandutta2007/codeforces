#include <stdio.h>

#include <set>
#include <vector>

std::vector<int> adj[200000];
std::multiset<int> ms;

int dfs(int v, int p) {
  int maxd = -1;
  for (int c : adj[v])
    if (c != p)
      maxd = std::max(maxd, dfs(c, v));
  if (maxd >= 0)
    ms.erase(ms.find(maxd));
  ms.insert(maxd + 1);
  return maxd + 1;
}

long long solve1(int n, int r, int minw) {
  int w = std::max(minw, (n / 2) - r);
  int b = n - r - w;
  return 1LL * w * (r - b);
}

long long solve(int n, int k) {
  dfs(0, -1);

  int minw = 0;
  long long ans = solve1(n, 0, minw);
  for (int r = 1; r <= k; r++) {
    if (!ms.empty()) {
      auto it = ms.end();
      --it;
      minw += *it;
      ms.erase(it);
    } else {
      minw -= 1;
    }
    ans = std::max(ans, solve1(n, r, minw));
  }
  return ans;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  printf("%lld\n", solve(n, k));
}