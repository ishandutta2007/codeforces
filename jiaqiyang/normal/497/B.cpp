#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Info;

const int N = 200000 + 10, INF = 0x3f3f3f3f;

int n, a[N];

int sum[N][2], first[N][2];

int solve(int t) {
  int cnt[2] = {0, 0};
  for (int i = 0; i < n;) {
    int p = first[sum[i][0] + t][0], q = first[sum[i][1] + t][1];
    if ((i = std::min(p, q)) == INF) return 0;
    ++cnt[p > q];
  }
  int res = std::max(cnt[0], cnt[1]);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n;) {
    int p = first[sum[i][0] + t][0], q = first[sum[i][1] + t][1];
    i = std::min(p, q);
    if (++cnt[p > q] == res && i < n) return 0;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) sum[i][0] = sum[i - 1][0], sum[i][1] = sum[i - 1][1], ++sum[i][--a[i]];
  memset(first, 0x3f, sizeof first);
  for (int i = n; i > 0; --i) first[sum[i][0]][0] = i, first[sum[i][1]][1] = i;
  std::vector<Info> ans;
  for (int t = 1; t <= n; ++t) {
    int s = solve(t);
    if (s) ans.push_back(Info(s, t));
  }
  printf("%d\n", ans.size());
  std::sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); ++i) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}