#include <cstdio>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef std::pair<int, int> Edge;

const int N = 100000 + 10;

int n, m;
int a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  static int order[N];
  for (int i = 1; i <= m; ++i) scanf("%d%d", &a[i], &b[i]), order[i] = i;
  std::sort(order + 1, order + m + 1, [=] (int lhs, int rhs) {
    return a[lhs] < a[rhs] || (a[lhs] == a[rhs] && b[lhs] > b[rhs]);
  });
  std::vector<int> cur;
  std::vector<Edge> pool;
  static Edge ans[N];
  for (int it = 1; it <= m; ++it) {
    int i = order[it];
    if (b[i]) {
      cur.push_back(a[i]);
      ans[i] = Edge(cur.size(), cur.size() + 1);
      for (int j = 0; j + 1 < cur.size() && pool.size() < m; ++j) pool.push_back(Edge(j + 1, cur.size() + 1));
    } else {
      if (pool.empty()) return puts("-1"), 0;
      ans[i] = pool.back();
      pool.pop_back();
    }
  }
  for (int i = 1; i <= m; ++i) printf("%d %d\n", ans[i].fst, ans[i].snd);
  return 0;
}