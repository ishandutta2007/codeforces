#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;

int n, sum[N];
char s[N];

int main() {
  scanf(" %s", s + 1);
  n = strlen(s + 1);
  static int suf[N];
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1];
    if (s[i] == '(') ++sum[i]; else --sum[i];
    if (sum[i] < 0) return puts("-1"), 0;
  }
  suf[n] = sum[n];
  for (int i = n - 1; i > 0; --i) suf[i] = std::min(sum[i], suf[i + 1]);
  static int ans[N];
  int det = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '#') {
      int cur = suf[i] - det;
      ans[i] = cur + 1;
      det = suf[i];
    }
  }
  if (det < suf[n]) return puts("-1"), 0;
  for (int i = 1; i <= n; ++i) if (s[i] == '#') printf("%d\n", ans[i]);
  return 0;
}