#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 10000000 + 10;

int n, m;
char s[N], ans[N];

int p[N], q[N], tot;

void duval() {
  for (int i = 0; i < n;) {
    int j = i, k = i + 1;
    for (; k < n && s[j] <= s[k]; ++k) j = (s[j] < s[k] ? i : (j + 1));
    for (p[tot] = i, q[tot++] = k - j; i <= j;) i += k - j;
  }
}

int z[N];

void init() {
  z[0] = 2 * n + 1;
  for (int i = 1, j = 0, r = 0; i <= 2 * n; ++i) {
    z[i] = std::max(std::min(r - i, z[i - j]), 0);
    while (s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] > r) r = i + z[j = i];
  }
}

void solve(char *res, int len) {
  int k = 2 * n + 1 - len;
  int t = z[k];
  strncpy(res, s[t] < s[k + t] ? s : (s + k), len);
}

int main() {
  scanf(" %s%d", s, &m);
  n = strlen(s);
  std::reverse(s, s + n);
  std::reverse_copy(s, s + n, s + n + 1);
  s[n] = '#';
  init();
  duval();
  int l = n;
  for (; tot && m > 2; --m) {
    --tot;
    strncpy(ans + n - l, s + p[tot], l - p[tot]);
    l = p[tot];
    if (q[tot] == 1) {
      for (; tot && q[tot - 1] == 1; l = p[--tot]) strncpy(ans + n - l, s + p[tot - 1], l - p[tot - 1]);
    }
  }
  if (m == 1 || tot < 2) {
    solve(ans + n - l, l);
  } else {
    static char temp[N];
    strcpy(temp, ans);
    strncpy(ans + n - l, s + p[tot - 1], l - p[tot - 1]);
    strncpy(temp + n - l, s + p[tot - 2], l - p[tot - 2]);
    solve(ans + n - p[tot - 1], p[tot - 1]);
    solve(temp + n - p[tot - 2], p[tot - 2]);
    if (strcmp(temp, ans) < 0) strcpy(ans, temp);
    int k = 0;
    for (int i = 1; i < l; ++i) {
      int a = 2 * n + 1 - l + k;
      int t = z[a];
      if (t < i - k) {
        if (s[a + t] < s[t]) k = i;
      } else {
        t = z[i - k];
        if (s[t] < s[i - k + t]) k = i;
      }
    }
    strncpy(temp + n - l, s + 2 * n + 1 - l, k);
    strncpy(temp + n - l + k, s, l - k);
    if (strcmp(temp, ans) < 0) strcpy(ans, temp);
  }
  puts(ans);
  return 0;
}