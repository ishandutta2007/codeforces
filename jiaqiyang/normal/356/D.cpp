#include <cstdio>
#include <bitset>
#include <vector>
#include <numeric>
#include <algorithm>

const int N = 70000 + 10, S = 7;

int n, p, s, a[N];

bool flag[N];

inline bool comp(int x, int y) { return a[x] < a[y]; }

int c[N];
std::vector<int> adj[N];

std::bitset<N> f[N / S + S];

bool init() {
  f[0][0] = 1;
  int i;
  for (i = 0; S * i < n; ++i) {
    std::bitset<N> &cur = f[i + 1] = f[i];
    for (int j = 0, k; j < S && (k = S * i + j) < n; ++j) if (k != p) cur |= cur << a[k];
  }
  int t = s - a[p];
  if (!f[i][t]) return false;
  while (--i >= 0) {
    for (int mask = 0; mask < (1 << S); ++mask) {
      bool temp = true;
      int val = 0;
      for (int j = 0, k; j < S && (k = S * i + j) < n; ++j) {
        if (mask >> j & 1) {
          if (k == p) {
            temp = false;
            break;
          }
          val += a[k];
        }
      }
      if (temp && t >= val && f[i][t - val]) {
        t -= val;
        for (int j = 0, k; j < S && (k = S * i + j) < n; ++j) if (mask >> j & 1) flag[k] = true;
        break;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  p = std::max_element(a, a + n) - a;
  if (s < a[p]) return puts("-1"), 0;
  flag[p] = true;
  if (!init()) return puts("-1"), 0;
  std::vector<int> pool;
  for (int i = 0; i < n; ++i) if (!flag[i]) pool.push_back(i); else c[i] = a[i];
  std::sort(pool.begin(), pool.end(), comp);
  pool.push_back(p);
  for (int i = 0; i < pool.size(); ++i) {
    int x = pool[i];
    c[x] = a[x];
    if (i) adj[x].push_back(pool[i - 1]), c[x] -= a[pool[i - 1]];
  }
  if (std::accumulate(c, c + n, 0LL) != s) return puts("-1"), 0;
  for (int i = 0; i < n; ++i) {
    printf("%d %d", c[i], adj[i].size());
    for (int j = 0; j < adj[i].size(); ++j) printf(" %d", adj[i][j] + 1);
    putchar('\n');
  }
  return 0;
}