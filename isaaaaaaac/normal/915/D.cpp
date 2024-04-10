#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 505;
const int M = 1e5 + 5;

struct edge {
  int nxt, to;
} e[M];
int fir[N];
int vis[N], cur = 0;
int fail, rec[N];
bool now[N];

inline int dfs(int x) {
  if (fail) return 0;
  if (vis[x] == cur) return rec[x];
  vis[x] = cur;
  now[x] = 1;
  int t = 0;
  for (int i = fir[x]; i; i = e[i].nxt) {
    if (e[i].to == cur) t ++;
    else if (vis[e[i].to] != cur) t += dfs(e[i].to);
    else if (now[e[i].to]) fail = 1;
    else t += rec[e[i].to];
  }
  rec[x] = t;
  now[x] = 0;
  return t;
}

int main() {
  int n, m, x, y, cnt = 0;
  scanf("%d%d", &n, &m);
  for (; m; m --) {
    scanf("%d%d", &x, &y);
    e[++ cnt] = (edge) { fir[x], y }; fir[x] = cnt;
  }
  for (int i = 1; i <= n; i ++) {
    cur ++;
    fail = 0;
    int have = 0;
    memset(rec, 0, sizeof rec);
    for (int j = fir[i]; j && !fail && have < 2; j = e[j].nxt)
      if (dfs(e[j].to)) have ++;
    for (int j = 1; j <= n; j ++)
      if (vis[j] != cur) dfs(j);
    // if (!fail && have <= 1) {
    //   cerr << i << endl;
    //   memset(vis, 0, sizeof vis);
    //   for (int j = fir[i]; j; j = e[j].nxt)
    //     cerr << dfs(e[j].to) << endl;
    // }
    if (!fail && have <= 1) return puts("YES"), 0;
  }
  puts("NO");
  return 0;
}