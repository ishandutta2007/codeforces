#include <cstdio>
#include <cstring>
#include <algorithm>


constexpr int N(3e5 + 5);
int n, k, a[N];
char s[N];
int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < k; i++)
      a[i] = -1;
    bool ans = 1;
    for (int i = 0, j; i < n; i++) {
      if (s[i] == '?') continue;
      j = i % k;
      if (a[j] == -1) {
        a[j] = s[i] - '0';
      } else if (a[j] != s[i] - '0'){
        ans = 0;
        break;
      }
    }
    if (ans) {
      for (int i = 0, j, c[2] = {}; i < n; i++) {
        j = i % k;
        if (s[i] == '?' && a[j] != -1)
          s[i] = a[j] + '0';
        if (s[i] != '?')
          c[s[i] - '0']++;
        if (i - k >= 0 && s[i - k] != '?')
          c[s[i - k] - '0']--;
        if (std::max(c[0], c[1]) > k >> 1) {
          ans = 0;
          break;
        }
      }
    }
    puts(ans ? "YES" : "NO");
  }
  return 0;
}