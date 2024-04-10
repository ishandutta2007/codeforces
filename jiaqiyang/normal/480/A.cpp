#include <cstdio>
#include <algorithm>

typedef std::pair<int, int> Info;

const int N = 5000 + 10;

int n;
Info info[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &info[i].first, &info[i].second);
  std::sort(info + 1, info + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (info[i].second >= ans) ans = info[i].second; else ans = info[i].first;
  printf("%d\n", ans);
  return 0;
}