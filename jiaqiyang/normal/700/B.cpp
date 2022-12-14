#include <cstdio>
#include <vector>

typedef long long i64;

const int N = 200000 + 10;

int n, k, cnt[N];
std::vector<int> adj[N];

void init() {
  scanf("%d%d", &n, &k);
  for (int i = 2 * k; i--;) {
    int u;
    scanf("%d", &u);
    ++cnt[u];
  }
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

i64 ans = 0;

void dfs(int a, int fa = 0) {
  for (auto b : adj[a]) if (b != fa) dfs(b, a), cnt[a] += cnt[b];
  ans += std::min(cnt[a], 2 * k - cnt[a]);
}

int main() {
  init();
  dfs(1);
  printf("%lld\n", ans);
  return 0;
}