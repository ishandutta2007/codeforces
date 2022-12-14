#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Edge;

const int N = 100000 + 10;

int n, p[N];

int m;
std::vector<int> cycle[N], mem[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (int i = 1; i <= n; ++i) {
    if (p[i] == i) {
      puts("YES");
      for (int j = 1; j <= n; ++j) if (i != j) printf("%d %d\n", i, j);
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    static bool flag[N];
    if (flag[i]) continue;
    ++m;
    for (int j = i; !flag[j]; j = p[j]) flag[j] = true, cycle[m].push_back(j);
    mem[cycle[m].size()].push_back(m);
    if (cycle[m].size() & 1) return puts("NO"), 0;
  }
  if (mem[2].empty()) return puts("NO"), 0;
  puts("YES");
  int a = mem[2][0];
  printf("%d %d\n", cycle[a][0], cycle[a][1]);
  for (int i = 1; i <= m; ++i) {
    if (i == a) continue;
    for (int j = 0; j < cycle[i].size(); ++j) printf("%d %d\n", cycle[i][j], cycle[a][j & 1]);
  }
  return 0;
}