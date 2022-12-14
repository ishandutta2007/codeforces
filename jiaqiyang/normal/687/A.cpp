#include <cstdio>
#include <vector>
#include <iterator>

const int N = 100000 + 10;

int n, m;
int anc[N], col[N];

int find(int x) {
  if (anc[x] == x) return x;
  int y = find(anc[x]);
  col[x] ^= col[anc[x]];
  return anc[x] = y;
}

bool meld(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return col[x] != col[y];
  anc[a] = b;
  col[a] ^= (col[x] == col[y]);
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) anc[i] = i, col[i] = 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!meld(x, y)) return puts("-1"), 0;
  }
  static std::vector<int> pool[N][2];
  for (int i = 1; i <= n; ++i) pool[find(i)][col[i]].push_back(i);
  static std::vector<int> ans[2];
  for (int i = 1; i <= n; ++i) {
    if (pool[i][0].empty()) pool[i][0].swap(pool[i][1]);
    if (ans[1].empty()) ans[0].swap(ans[1]);
    std::copy(pool[i][0].begin(), pool[i][0].end(), std::back_inserter(ans[0]));
    std::copy(pool[i][1].begin(), pool[i][1].end(), std::back_inserter(ans[1]));
  }
  if (ans[0].empty() || ans[1].empty()) return puts("-1"), 0;
  for (int i = 0; i < 2; ++i) {
    printf("%d\n", ans[i].size());
    for (int j = 0; j < ans[i].size(); ++j) printf("%d ", ans[i][j]);
    putchar('\n');
  }
  return 0;
}