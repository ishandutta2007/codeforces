#include <cstdio>
#include <vector>

typedef std::pair<int, int> Edge;

const int N = 1 << 16;

int n, deg[N], s[N];

int main() {
  scanf("%d", &n);
  static int q[N];
  int r = 0;
  for (int i = 0; i < n; ++i) scanf("%d%d", &deg[i], &s[i]);
  for (int i = 0; i < n; ++i) if (deg[i] == 1) q[r++] = i;
  std::vector<Edge> ans;
  for (int i = 0; i < r; ++i) {
    int a = q[i], b = s[a];
    if (!deg[a]) continue;
    ans.push_back(Edge(a, b));
    s[b] ^= a;
    if (--deg[b] == 1) q[r++] = b;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}