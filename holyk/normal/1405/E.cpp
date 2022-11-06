#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> PII;
constexpr int N(3e5 + 5);

int n, q, a[N], ans[N];
std::vector<PII> g[N];

struct Node {
  int add, min;
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
inline void pushup(int o) {
  t[o].min = std::min(t[ls].min, t[rs].min);
}
inline void pushdown(int o) {
  if (t[o].add) {
    t[ls].add += t[o].add, t[rs].add += t[o].add;
    t[ls].min += t[o].add, t[rs].min += t[o].add;
    t[o].add = 0;
  }
}
void update(int o, int l, int r, int x, int z) {
  if (t[o].min >= z && r <= x) {
    t[o].add++, t[o].min++;
    return;
  }
  if (l == r) return;
  pushdown(o);
  int mid = l + r >> 1;
  update(ls, l, mid, x, z);
  if (x > mid && t[ls].min >= z) update(rs, mid + 1, r, x, z);
  pushup(o);
}
int ask(int o, int l, int r, int x) {
  if (l == r) return t[o].min;
  pushdown(o);
  int mid = l + r >> 1;
  return x <= mid ? ask(ls, l, mid, x) : ask(rs, mid + 1, r, x);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]), a[i] = i - a[i];
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x++, y = n - y;
    g[y].push_back(PII(x, i));
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 0) update(1, 1, n, i, a[i]);
    for (auto s : g[i])
      ans[s.second] = ask(1, 1, n, s.first);
  }
  for (int i = 1; i <= q; i++)
    printf("%d\n", ans[i]);
  return 0;
}