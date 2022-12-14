#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 1000000 + 10;

int n, m;
char s[N], t[N];

int dispatch(char c) {
  switch (c) {
    case 'R': return 1;
    case 'G': return 2;
    case 'B': return 3;
  }
}

int f[N], g[N];
int cnt[N][16];

int main() {
  scanf(" %s %s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = 1; i <= n; ++i) s[i] = dispatch(s[i]);
  for (int i = 1; i <= m; ++i) t[i] = dispatch(t[i]);
  for (int i = 1; i <= m; ++i) {
    memcpy(cnt[i], cnt[i - 1], sizeof cnt[i - 1]);
    ++cnt[i][(t[i] << 2) | t[i - 1]];
  }
  i64 ans = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && t[j] != s[i]) ++j;
    f[i] = j;
    if (t[j] == s[i]) ++j;
  }
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && s[j] != t[i]) ++j;
    g[i] = j;
    if (s[j] == t[i]) ++j;
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    // x <= f[i]
    // i <= g[x]
    while (j <= m && i > g[j]) ++j;
    int l = j, r = std::min(f[i], m);
    if (l > r) break;
    ans += r - l + 1;
    if (i > 1 && s[i] != s[i - 1]) {
      int t = (s[i - 1] << 2) | s[i];
      ans -= cnt[r][t] - cnt[l - 1][t];
    }
  }
  printf("%lld\n", ans);
  return 0;
}