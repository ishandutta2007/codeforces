#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int mod = 998244353;
const int N = 415;
int n, m, c[N][N], d[N][N];
vector<int> G[N];
void bfs(int s, int *d, int *c) {
  fill(d + 1, d + n + 1, N);
  queue<int> q;
  q.push(s); d[s] = 0; c[s] = 1;
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int v : G[u]) if(d[v] == N) {
      d[v] = d[u] + 1; c[v] = c[u]; q.push(v);
    } else if(d[v] == d[u] + 1) {
      c[v] = 2;
    }
  }
}
int calc(int s, int t) {
  if(c[s][t] == 2) return 0;
  const int dis = d[s][t];
  int ans = 1;
  rep(i, 1, n) if(d[s][i] + d[i][t] != dis) {
    int z = 0;
    for(int v : G[i]) {
      if(d[s][v] + 1 == d[s][i] && d[t][v] + 1 == d[t][i]) {
        z ++;
      }
    }
    ans = 1ll * ans * z % mod;
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  rep(i, 1, m) {
    scanf("%d%d", &u, &v);
    G[u].pb(v); G[v].pb(u);
  }
  rep(s, 1, n) bfs(s, d[s], c[s]);
  rep(s, 1, n) rep(t, 1, n)
    printf("%d%c", calc(s, t), " \n"[t == n]);
  return 0;
}