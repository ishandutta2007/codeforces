#include <cstdio>
#include <map>
#include <algorithm>

typedef std::pair<int, int> Pair;

const int N = 100000 + 10;

int n, m;

struct Info {
  int x, y, z;
  inline bool operator< (const Info &rhs) const {
    return x < rhs.x;
  }
} info[N], que[N];

int k[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &info[i].x, &info[i].y), info[i].z = i;
  std::sort(info + 1, info + n + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &que[i].x, &que[i].y, &k[i]), que[i].z = i;
  std::sort(que + 1, que + m + 1);
  std::multimap<int, int> pool;
  static int ans[N];
  for (int i = 1, j = 1; i <= n; ++i) {
    for (; j <= m && que[j].x <= info[i].x; ++j) pool.insert(std::make_pair(que[j].y, que[j].z));
    std::multimap<int, int>::iterator it = pool.lower_bound(info[i].y);
    if (it == pool.end()) return puts("NO"), 0;
    if (--k[ans[info[i].z] = it->second] == 0) pool.erase(it);
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}