#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Info;

const int N = 300000 + 10;

int n, m, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::vector<int> sorted(a + 1, a + n + 1);
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;
  std::vector<Info> ans;
  for (int i = 1; i <= n;) {
    static int tag[N], cnt;
    ++cnt;
    int j;
    for (j = i; j <= n; ++j) {
      if (tag[a[j]] == cnt) break;
      tag[a[j]] = cnt;
    }
    if (j <= n) {
      ans.push_back(Info(i, j));
    } else if (ans.empty()) {
      return puts("-1"), 0;
    } else {
      ans.back().second = n;
    }
    i = j + 1;
  }
  printf("%u\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}