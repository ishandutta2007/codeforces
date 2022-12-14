#include <stdio.h>
#include <cctype>
#include <queue>
#include <vector>
#include <algorithm>

const int N = 1000 + 10, M = N * N, S = 40000;

int n, m, q;

struct Edge {
  int x, y, z;
  inline bool operator< (const Edge &rhs) const {
    return z < rhs.z;
  }
} edge[M];

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

std::vector<Edge> pool[S];

int anc[N], col[N];

int find(int x) {
  if (anc[x] == x) return x;
  int y = find(anc[x]);
  col[x] ^= col[anc[x]];
  return anc[x] = y;
}

int meld(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return col[x] == col[y] ? -1 : 0;
  anc[a] = b;
  col[a] ^= (col[x] == col[y]);
  return 1;
}

void init() {
  for (int i = 0; i * S < m; ++i) {
    int l = i * S, r = std::min(l + S, m);
    std::vector<Edge> cur(edge + l, edge + r);
    std::sort(cur.begin(), cur.end());
    for (int j = 1; j <= n; ++j) col[anc[j] = j] = 0;
    for (int j = cur.size() - 1; j >= 0; --j) {
      int t = meld(cur[j].x, cur[j].y);
      if (t) pool[i].push_back(cur[j]);
      if (t == -1) break;
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++i) edge[i].x = nextInt(), edge[i].y = nextInt(), edge[i].z = nextInt();
  init();
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    static Edge cur[M];
    int tot = 0;
    for (; l < r && l % S; ++l) cur[++tot] = edge[l];
    for (; l < r && r % S; --r) cur[++tot] = edge[r - 1];
    for (; l < r; l += S)
      for (int i = 0, id = l / S; i < pool[id].size(); ++i)
        cur[++tot] = pool[id][i];
    std::sort(cur + 1, cur + tot + 1);
    int ans = -1;
    for (int i = 1; i <= n; ++i) col[anc[i] = i] = 0;
    for (int i = tot; i > 0; --i) {
      const Edge &e = cur[i];
      if (meld(e.x, e.y) == -1) {
        ans = e.z;
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}