#include <cstdio>
#include <vector>

const int N = 100000 + 10;

int n, c[N], x[N], y[N];
std::vector<int> adj[N];

bool check(int a, int fa = 0) {
  for (auto b : adj[a]) {
    if (b == fa) continue;
    if (!check(b, a) || (fa && c[b] != c[a])) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i < n; ++i) adj[x[i]].push_back(y[i]), adj[y[i]].push_back(x[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  for (int i = 1; i < n; ++i) {
    if (c[x[i]] == c[y[i]]) continue;
    if (check(x[i])) printf("YES\n%d\n", x[i]); else if (check(y[i])) printf("YES\n%d\n", y[i]); else puts("NO");
    return 0;
  }
  printf("YES\n1\n");
  return 0;
}