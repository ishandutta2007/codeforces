#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;

const int off = 23, MAXN = 3e5 + 5;

int par[MAXN][off];

int n, q, ts[MAXN], t[MAXN], sol[MAXN], dub[MAXN];
vector<int> e[MAXN];
vector<pair<int, int> > in[MAXN];

void dfs(int x, int pr, int crdub = 0) {
   dub[x] = crdub;
   ts[x] ++;
   par[x][0] = pr;
   rep(i, off - 1) par[x][i + 1] = par[par[x][i]][i];
   for(auto y : e[x]) dfs(y, x, crdub + 1);
   for(auto y : e[x]) ts[x] += ts[y];
   for(auto y : e[x]) t[x] = max(t[x], ts[y]);
}
//int nd, db;
pair<int, int> solve(int x) {

   int nd = -1, db = MAXN;

   for(auto y : e[x]) {
      auto pp = solve(y);
      if(pp.second <= db) {
         db = pp.second;
         nd = pp.first;
      }
   }

   for(auto y : in[x]) {
      if(y.second <= db) {
         nd = y.first;
         db = y.second;
      }
   }
   sol[x + 1] = nd;
   return {nd, db};
}

void f(int node) {
   int x = node;
   int y = t[x] * 2;
   for(int i = off - 1; i >= 0; --i)
      if(ts[par[x][i]] < y) x = par[x][i];

   if(max(ts[x] - ts[node], t[node]) * 2 > ts[x])
      x = par[x][0];

   if(t[node] * 2 <= ts[node]) x = node;

   if(max(ts[x] - ts[node], t[node]) * 2 > ts[x]) return;

   int X = x;

   for(int i = off - 1; i >= 0; --i)
      if(max(ts[par[x][i]] - ts[node], t[node]) * 2 <= ts[par[x][i]]) x = par[x][i];

   in[X].push_back({node + 1, dub[x]});
}

int main() {
   scanf("%d%d", &n, &q);
   rep(i, n - 1) {
      int x; scanf("%d", &x);
      e[--x].push_back(i + 1);
   }
   dfs(0, 0);
   rep(i, n) f(i);
   auto dummy = solve(0);
   rep(i, q) {
      int x; scanf("%d", &x);
      printf("%d\n", sol[x]);
   }
}