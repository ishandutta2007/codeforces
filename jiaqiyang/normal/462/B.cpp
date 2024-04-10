#include <cstdio>
#include <cinttypes>
#include <algorithm>
#include <functional>

const int N = 100000 + 10;

int n, k;
char s[N];

int main() {
  scanf("%d%d %s", &n, &k, s);
  static int cnt[26];
  for (char *it = s; *it != '\0'; ++it) cnt[*it - 'A']++;
  std::sort(cnt, cnt + 26, std::greater<int>());
  int64_t ans = 0;
  for (int i = 0; i < 26; ++i) {
    int cur = std::min(k, cnt[i]);
    ans += (int64_t)cur * cur;
    k -= cur;
  }
  printf("%" PRId64 "\n", ans);
  return 0;
}