#include <stdio.h>
#include <cctype>
#include <vector>

const int N = 300000 + 10;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, q;
std::vector<int> adj[N];

int ans[N], fa[N], size[N], mx[N];

void dfs(int a) {
  size[a] = 1;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == fa[a]) continue;
    fa[b] = a;
    dfs(b);
    size[a] += size[b];
    mx[a] = std::max(mx[a], size[b]);
  }
}

void solve(int a) {
  ans[a] = a;
  int val = mx[a];
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == fa[a]) continue;
    solve(b);
    int c = ans[b];
    while (c != a && std::max(mx[c], size[a] - size[c]) >= std::max(mx[fa[c]], size[a] - size[fa[c]])) c = fa[c];
    int temp = std::max(mx[c], size[a] - size[c]);
    if (temp < val) {
      val = temp;
      ans[a] = c;
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++i) {
    int j = nextInt();
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  dfs(1);
  solve(1);
  while (q--) printf("%d\n", ans[nextInt()]);
  return 0;
}