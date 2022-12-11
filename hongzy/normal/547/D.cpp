#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e6 + 10;
const int M = 2e5;
struct Edge { int v, nxt; } e[N];
int n, m, ec, d[N], hd[N];
void add(int u, int v) {
  e[++ ec] = (Edge) {v, hd[u]}; hd[u] = ec;
}
bool vis[N];
char ans[N];
void fleury(int u) {
  for(int &i = hd[u]; i; ) {
    int v = e[i].v, num = (i + 1) >> 1, dir = i & 1;
    i = e[i].nxt;
    if(vis[num]) continue ;
    vis[num] = 1;
    ans[num] = dir ? 'r' : 'b';
    fleury(v);
  }
}
int main() {
  scanf("%d", &n);
  int u, v;
  rep(i, 1, n) {
    scanf("%d%d", &u, &v);
    ++ d[u]; ++ d[M + v];
    add(u, M + v); add(M + v, u);
  }
  rep(i, 1, 2 * M) if(d[i] & 1)
    add(i, 2 * M + 1), add(2 * M + 1, i);
  rep(i, 1, 2 * M + 1) fleury(i);
  ans[n + 1] = 0;
  puts(ans + 1);
  return 0;
}