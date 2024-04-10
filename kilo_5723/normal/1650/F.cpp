#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
struct triple {
  int t, p, i;
  triple() {}
  triple(int t, int p, int i) : t(t), p(p), i(i) {}
};
const int inf = 1e9 + 5;
const int maxn = 1e5 + 5, maxm = 205;
int a[maxn];
vector<triple> d[maxn];
int dp[maxm];
vector<triple> lis[maxm];
vector<triple> solve(const vector<triple> &arr) {
  fill(dp, dp + maxm, inf);
  for (int i = 0; i < maxm; i++) lis[i].clear();
  dp[0] = 0;
  for (auto tp : arr)
    for (int i = maxm - 1; i >= tp.p; i--)
      if (dp[i] > dp[i - tp.p] + tp.t) {
        dp[i] = dp[i - tp.p] + tp.t;
        lis[i] = lis[i - tp.p];
        lis[i].push_back(tp);
      }
  int mn = inf, pos = -1;
  for (int i = 100; i < maxm; i++)
    if (dp[i] < mn) {
      mn = dp[i];
      pos = i;
    }
  if (pos == -1)
    return {triple(inf, inf, -1)};
  else
    return lis[pos];
}
vector<int> ans;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      d[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int e, t, p;
      scanf("%d%d%d", &e, &t, &p);
      d[e].push_back(triple(t, p, i));
    }
    int t = 0;
    bool flg = true;
    ans.clear();
    for (int i = 1; i <= n; i++) {
      vector<triple> res = solve(d[i]);
      for (auto tp : res) t += tp.t;
      if (t > a[i]) flg = false;
      for (auto tp : res) ans.push_back(tp.i);
    }
    if (!flg) {
      puts("-1");
      continue;
    }
    printf("%lu\n", ans.size());
    for (auto v : ans) printf("%d ", v);
    puts("");
  }
  return 0;
}