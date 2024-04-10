#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct triple {
  int l, r, i;
  triple() {}
  triple(int l, int r, int i) : l(l), r(r), i(i) {}
};
bool operator!=(triple a, triple b) {
  if (a.l != b.l) return true;
  if (a.r != b.r) return true;
  if (a.i != b.i) return true;
  return false;
}
const triple nil = triple(-1, -1, -1);
const int maxn = 1e3 + 5, maxm = 2e3 + 5;
triple sub[maxm];
char s[maxn], t[maxn][maxn];
int dp[maxn];
int get(char s[], int len) {
  int ans = 0;
  for (int i = 0; i < len; i++) {
    ans *= 10;
    ans += s[i] - '0' + 1;
  }
  return ans;
}
vector<triple> ans;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    fill(sub, sub + maxm, nil);
    for (int i = 0; i < n; i++) scanf("%s", t[i]);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (j + 2 <= m) sub[get(t[i] + j, 2)] = triple(j + 1, j + 2, i + 1);
        if (j + 3 <= m) sub[get(t[i] + j, 3)] = triple(j + 1, j + 3, i + 1);
      }
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
      dp[i] = -1;
      if (i >= 2 && ~dp[i - 2] && sub[get(s + i - 2, 2)] != nil) dp[i] = i - 2;
      if (i >= 3 && ~dp[i - 3] && sub[get(s + i - 3, 3)] != nil) dp[i] = i - 3;
    }
    if (dp[m] == -1) {
      puts("-1");
      continue;
    }
    ans.clear();
    while (m) {
      int t = m - dp[m];
      m = dp[m];
      ans.push_back(sub[get(s + m, t)]);
    }
    printf("%lu\n", ans.size());
    reverse(ans.begin(), ans.end());
    for (auto tr : ans) printf("%d %d %d\n", tr.l, tr.r, tr.i);
  }
  return 0;
}