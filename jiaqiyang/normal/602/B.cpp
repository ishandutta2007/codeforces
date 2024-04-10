#include <cstdio>
#include <vector>
#include <algorithm>

#define fst first
#define snd second

typedef long long i64;
typedef std::pair<int, int> Info;

const int N = 100000 + 10;

int n, a[N];
std::vector<Info> cur;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n && a[j] == a[i]) ++j;
    cur.push_back(Info(a[i], j - i));
    i = j;
  }
  static int cnt[N];
  std::vector<int> sum(cur.size());
  for (int i = 0; i < sum.size(); ++i) sum[i] = cur[i].snd;
  for (int i = 1; i < sum.size(); ++i) sum[i] += sum[i - 1];
  int ans = cur[0].snd;
  int tot = 0; //cnt[cur[0].fst] = 1;
  for (int i = 0, j = 0; i < cur.size(); ++i) {
    for (; j < cur.size(); ++j) {
      int t = cur[j].fst;
      if (cnt[t] || tot < 2) tot += (cnt[t]++ == 0); else break;
    }
    ans = std::max(ans, sum[j - 1] - (i ? sum[i - 1] : 0));
    tot -= (--cnt[cur[i].fst] == 0);
  }
  printf("%d\n", ans);
  return 0;
}