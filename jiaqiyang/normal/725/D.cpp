#include <cstdio>
#include <queue>
#include <algorithm>

typedef long long i64;
typedef std::pair<i64, i64> Info;

const int N = 300000 + 10;

int n, p[N];
i64 t[N], w[N];

inline bool comp(int a, int b) { return t[a] > t[b]; }

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld%lld", &t[i], &w[i]), p[i] = i;
  std::sort(p + 2, p + n + 1, comp);
  std::priority_queue<i64> heap;
  int ans = n;
  i64 cur = t[1];
  for (int i = 2;;) {
    for (; i <= n && t[p[i]] > cur; ++i) heap.push(-(w[p[i]] - t[p[i]] + 1));
    ans = std::min<int>(ans, heap.size() + 1);
    if (heap.empty()) break;
    i64 x = -heap.top();
    heap.pop();
    if (cur >= x) cur -= x; else break;
  }
  printf("%d\n", ans);
  return 0;
}