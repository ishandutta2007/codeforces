#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

const int N = 200000 + 10, MOD = 1000000007;

int h, w, n;
int u[N], l[N], r[N], s[N];

std::map<std::pair<int, int>, int> res;

inline int pos(int l, int r) { return (l + r) | (l != r); }

std::priority_queue<std::pair<int, int>> heap[2 * N];

void modify(int l, int r, int p, int q, int x) {
  if (p <= l && r <= q) {
    heap[pos(l, r)].emplace(u[x], x);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, q, x);
  if (q > mid) modify(mid + 1, r, p, q, x);
}

inline int max(int x, int y) { return u[x] > u[y] ? x : y; }

int query(int l, int r, int p, int q) {
  int id = pos(l, r);
  while (!heap[id].empty() && ::r[heap[id].top().second] < q) heap[id].pop();
  int res = (heap[id].empty() ? 0 : heap[id].top().second);
  if (l == r) return res;
  int mid = (l + r) >> 1;
  return max(res, p <= mid ? query(l, mid, p, q) : query(mid + 1, r, p, q));
}

int sorted[N], tot;

void init() {
  scanf("%d%d%d", &h, &w, &n);
  std::vector<std::pair<int, int>> p, q;
  ++h;
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d", &u[i], &l[i], &r[i], &s[i]);
    s[i] = std::min(s[i] + u[i], h);
    p.emplace_back(l[i], i);
    if (l[i] > 1) q.emplace_back(l[i] - 1, u[i]);
    if (r[i] < w) q.emplace_back(r[i] + 1, u[i]);
    sorted[++tot] = u[i];
    sorted[++tot] = s[i];
  }
  sorted[++tot] = h;
  for (int i = 1; i <= w; ++i) q.emplace_back(i, h);
  std::sort(sorted + 1, sorted + tot + 1);
  tot = std::unique(sorted + 1, sorted + tot + 1) - sorted - 1;
  auto f = [&] (int x) { return std::lower_bound(sorted + 1, sorted + tot + 1, x) - sorted; };
  for (int i = 1; i <= n; ++i) u[i] = f(u[i]), s[i] = f(s[i]);
  for (auto &it : q) it.second = f(it.second);
  std::sort(p.begin(), p.end());
  std::sort(q.begin(), q.end());
  int i = 0;
  for (auto it : q) {
    for (; i < p.size() && p[i].first <= it.first; ++i) {
      int j = p[i].second;
      modify(1, tot, u[j], s[j], j);
    }
    res[it] = query(1, tot, it.second, it.first);
  }
}

std::map<std::pair<int, int>, int> f;

int solve(int x, int y) {
  if (f.count({x, y})) return f[{x, y}];
  int z = res[{x, y}];
  if (!z) return f[{x, y}] = 1;
  int cur = 0, p = l[z] - 1, q = r[z] + 1;
  if (!p) p = q;
  if (q > w) q = p;
  return f[{x, y}] = (solve(p, u[z]) + solve(q, u[z])) % MOD;
}

int main() {
  init();
  int ans = 0;
  for (int i = 1; i <= w; ++i) ans = (ans + solve(i, tot)) % MOD;
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}