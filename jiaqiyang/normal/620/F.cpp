#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 50000 + 10, M = 1000000 + 10, L = 20, S = (L + 3) * N;

int n, m, size, a[N], l[N], r[N];

int sum[M];

namespace MinTrie {

int tot;
int next[S][2], min[S];

int copy(int orig) {
  ++tot;
  next[tot][0] = next[orig][0];
  next[tot][1] = next[orig][1];
  min[tot] = min[orig];
  return tot;
}

int memTot;

inline void save() { memTot = tot; }
inline void load() { tot = memTot; }

inline void clear() { tot = 0, min[0] = M; }

int insert(int orig, int p, int v) {
  int res = copy(orig), cur = res;
  for (int i = L - 1; i >= 0; --i) {
    int c = p >> i & 1;
    min[cur] = std::min(min[cur], v);
    cur = next[cur][c] = copy(next[cur][c]);
  }
  min[cur] = std::min(min[cur], v);
  return res;
}

int query(int id, int p, int v) {
  int res = 0;
  for (int i = L - 1; i >= 0; --i) {
    int c = p >> i & 1;
    int t = next[id][!c];
    if (min[t] <= v) res |= 1 << i, id = t; else id = next[id][c];
  }
  return res;
}

}

namespace MaxTrie {

int tot;

int memTot;

inline void save() { memTot = tot; }
inline void load() { tot = memTot; }

int next[S][2], max[S];

int copy(int orig) {
  ++tot;
  next[tot][0] = next[orig][0];
  next[tot][1] = next[orig][1];
  max[tot] = max[orig];
  return tot;
}

inline void clear() {
  tot = 0;
  next[0][0] = next[0][1] = max[0] = 0;
}

int insert(int orig, int p, int v) {
  int res = copy(orig), cur = res;
  for (int i = L - 1; i >= 0; --i) {
    int c = p >> i & 1;
    max[cur] = std::max(max[cur], v);
    int t = copy(next[cur][c]);
    cur = next[cur][c] = t;
  }
  max[cur] = std::max(max[cur], v);
  return res;
}

int query(int id, int p, int v) {
  int res = 0;
  for (int i = L - 1; i >= 0; --i) {
    int c = p >> i & 1;
    int t = next[id][!c];
    if (max[t] >= v) res |= 1 << i, id = t; else id = next[id][c];
  }
  return res;
}

}

struct State {
  int minId, maxId, val;
  inline void clear() { minId = maxId = val = 0; }
  State() { clear(); }
  void add(int x) {
    minId = MinTrie::insert(minId, sum[x - 1], x);
    maxId = MaxTrie::insert(maxId, sum[x], x);
    val = std::max(val, MinTrie::query(minId, sum[x], x));
    val = std::max(val, MaxTrie::query(maxId, sum[x - 1], x));
  }
};

int solve(int l, int r) {
  MinTrie::clear();
  MaxTrie::clear();
  State res;
  for (int i = l; i <= r; ++i) res.add(a[i]);
  return res.val;
}

std::vector<int> query[N];

inline bool comp(int x, int y) { return r[x] < r[y]; }

int main() {
  scanf("%d%d", &n, &m);
  size = sqrt(n) + .5;
  sum[0] = 0;
  for (int i = 1; i < M; ++i) sum[i] = sum[i - 1] ^ i;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d%d", &l[i], &r[i]), --l[i], --r[i];
  static int ans[N];
  for (int i = 0; i < m; ++i) if (l[i] / size == r[i] / size) ans[i] = solve(l[i], r[i]); else query[l[i] / size].push_back(i);
  for (int i = 0; i * size < n; ++i) {
    if (query[i].empty()) continue;
    std::sort(query[i].begin(), query[i].end(), comp);
    const int mid = (i + 1) * size;
    int p = mid;
    MinTrie::clear(), MaxTrie::clear();
    State state;
    for (int j = 0; j < query[i].size(); ++j) {
      for (; p <= r[query[i][j]]; ++p) state.add(a[p]);
      MinTrie::save(), MaxTrie::save();
      State cur = state;
      for (int q = l[query[i][j]]; q < mid; ++q) cur.add(a[q]);
      ans[query[i][j]] = cur.val;
      MinTrie::load(), MaxTrie::load();
    }
  }
  for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
  return 0;
}