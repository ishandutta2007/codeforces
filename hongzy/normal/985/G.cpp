#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ull = unsigned long long;
const int N = 2e5 + 10;
int n, m, eu[N], ev[N], deg[N], vis[N], tim;
vector<int> G[N], T[N];
ull all, a1, a2, a3, A, B, C;
ull calc(int u, int v, int w) {
  if(u > v) swap(u, v);
  if(v > w) swap(v, w);
  if(u > v) swap(u, v);
  return A * u + B * v + C * w;
}
ull S(ull l, ull r) {
  return (l + r) * (r - l + 1) / 2;
}
int main() {
  scanf("%d%d%llu%llu%llu", &n, &m, &A, &B, &C);
  rep(i, 0, m - 1) {
    scanf("%d%d", eu + i, ev + i);
    if(eu[i] > ev[i]) swap(eu[i], ev[i]);
    deg[eu[i]] ++; deg[ev[i]] ++;
    G[eu[i]].pb(ev[i]); G[ev[i]].pb(eu[i]);
  }
  rep(i, 0, m - 1) {
    deg[eu[i]] > deg[ev[i]] ? T[eu[i]].pb(ev[i]) : T[ev[i]].pb(eu[i]);
  }
  rep(i, 1, n - 2) all += B * i * i * (n - 1 - i) + S(0, i - 1) * A * (n - 1 - i) + S(i + 1, n - 1) * C * i;
  rep(i, 0, n - 1) {
    ++ tim;
    for(int v : T[i]) vis[v] = tim;
    for(int v : T[i]) for(int w : T[v]) if(vis[w] == tim) {
      a3 += calc(i, v, w);
    }
  }
  rep(i, 0, n - 1) {
    ull sl = 0, sr = 0;
    ull lc = 0, rc = 0;
    for(int v : G[i]) {
      (v <= i ? sl : sr) += v;
      (v <= i ? lc : rc) ++;
    }
    a2 += B * i * lc * rc + A * sl * rc + C * sr * lc;
    sort(G[i].begin(), G[i].end());
    sl = sr = lc = rc = 0;
    for(int j = 0; j < int(G[i].size()); j ++) {
      int v = G[i][j];
      if(v > i) break ;
      a2 += A * sl + (B * v + C * i) * lc;
      sl += v; lc ++;
    }
    for(int j = int(G[i].size()) - 1; ~j; j --) {
      int v = G[i][j];
      if(v < i) break ;
      a2 += (A * i + B * v) * rc + C * sr;
      sr += v; rc ++;
    }
  }
  a2 -= 3 * a3;
  rep(i, 0, n - 1) {
    for(int v : G[i]) if(i < v) {
      a1 += A * S(0, i - 1) + (B * i + C * v) * i;
      a1 += (A * i + B * v) * (n - 1 - v) + C * S(v + 1, n - 1);
      if(v - i > 1)
        a1 += (A * i + C * v) * (v - i - 1) + B * S(i + 1, v - 1);
    }
  }
  a1 -= 2 * a2 + 3 * a3;
  // LOG("a1 = %llu, a2 = %llu, a3 = %llu\n", a1, a2, a3);
  printf("%llu\n", all - a1 - a2 - a3);
  return 0;
}
// u,v\in S, u < v \sum Au+Bv
// [ (\sum Au)(\sum Bu)-\sum (A+B)u ]/2