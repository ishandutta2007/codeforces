#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <algorithm>

const int N = 5000 + 10;

int n, fa[N], size[N];
std::vector<int> adj[N];

std::vector<int> cur;

bool flag[N];

void select(int x) {
  for (int a = x; a > 1; a = fa[a]) {
    flag[a] = true;
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (!flag[b]) cur.push_back(size[b]);
    }
  }
}

bool solve(int x, int y, int z) {
  cur.clear();
  memset(flag, 0, sizeof flag);
  select(x);
  select(z);
  static std::bitset<N> mask;
  mask.reset();
  while (fa[y] > 1) y = fa[y];
  flag[y] = true;
  mask[size[y]] = 1;
  for (int i = 0; i < cur.size(); ++i) mask |= mask << cur[i];
  for (int i = 0; i < adj[1].size(); ++i) if (!flag[adj[1][i]]) mask |= mask << size[adj[1][i]];
  return mask[size[1] / 2 - 1];
}

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), adj[fa[i]].push_back(i);
  for (int i = n; i > 1; --i) size[i] = std::max(size[i], 1), size[fa[i]] += size[i];
  if (size[1] & 1) return puts("NO"), 0;
  if (2 * *std::max_element(size + 2, size + n + 1) >= size[1]) return puts("NO"), 0;
  puts(solve(a, b, c) && solve(b, c, d) ? "YES" : "NO");
  return 0;
}