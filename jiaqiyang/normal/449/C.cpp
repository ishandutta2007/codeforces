#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000 + 10;

int p[N], cnt;

void sieve() {
  static bool flag[N];
  cnt = 0;
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) p[++cnt] = i;
    for (int j = 1; j <= cnt && i * p[j] < N; ++j) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}

int n, cur[N], tot;
std::vector<int> pool[N];

void factor(int x) {
  tot = 0;
  for (int j = 1; j <= cnt && p[j] * p[j] <= x; ++j) {
    if (x % p[j] == 0) {
      cur[++tot] = p[j];
      while (x % p[j] == 0) x /= p[j];
    }
  }
  if (x > 1) cur[++tot] = x;
}

int main() {
  scanf("%d", &n);
  sieve();
  static std::pair<int, int> g[N];
  for (int i = 2; i <= n; ++i) {
    factor(i);
    g[i] = std::make_pair(tot, i);
  }
  std::sort(g + 2, g + n + 1);
  for (int i = 2; i <= n; ++i) {
    int t = g[i].second;
    factor(t);
    for (int j = tot; j > 0; --j) {
      if ((pool[cur[j]].size() & 1) || j == 1) {
        pool[cur[j]].push_back(t);
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 2; i <= n; ++i) ans += (pool[i].size() >> 1);
  printf("%d\n", ans);
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j + 1 < pool[i].size(); j += 2)
      printf("%d %d\n", pool[i][j], pool[i][j + 1]);
  return 0;
}