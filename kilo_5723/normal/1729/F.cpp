#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];
int ss[maxn];
int rem[9][2];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%s", s);
    int n = strlen(s);
    int w, m;
    scanf("%d%d", &w, &m);
    memset(rem, -1, sizeof(rem));
    int sum = 0;
    for (int i = 0; i < w; i++) sum += s[i] - '0';
    for (int i = 0; i + w <= n; i++) {
      if (!~rem[sum % 9][0])
        rem[sum % 9][0] = i;
      else if (!~rem[sum % 9][1])
        rem[sum % 9][1] = i;
      sum -= s[i];
      sum += s[i + w];
    }
    // for (int i = 0; i < 9; i++) printf("%d: %d %d ; ", i, rem[i][0],
    // rem[i][1]); puts("");
    ss[0] = 0;
    for (int i = 0; i < n; i++) ss[i + 1] = ss[i] + s[i] - '0';
    while (m--) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      pair<int, int> ans = {n + 1, n + 1};
      for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
          if ((i * (ss[r] - ss[l - 1]) + j) % 9 == k) {
            if (i == j && ~rem[i][1]) ans = min(ans, {rem[i][0], rem[i][1]});
            if (i != j && ~rem[i][0] && ~rem[j][0])
              ans = min(ans, {rem[i][0], rem[j][0]});
          }
      if (ans.first == n + 1)
        puts("-1 -1");
      else
        printf("%d %d\n", ans.first + 1, ans.second + 1);
    }
  }
  return 0;
}