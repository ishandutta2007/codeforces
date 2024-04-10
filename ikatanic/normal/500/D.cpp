#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100010;

vector<int> E[MAXN], W[MAXN];
int sz[MAXN];
int dad[MAXN];
int a[MAXN], b[MAXN], w[MAXN];

void dfs(int x, int d) {
  dad[x] = d;
  sz[x] = 1;
  REP(i, (int)E[x].size()) {
    int y = E[x][i];
    if (dad[x] != y) {
      dfs(y, x);
      sz[x] += sz[y];
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    scanf("%d %d %d", &a[i], &b[i], &w[i]);
    --a[i], --b[i];
    E[a[i]].push_back(b[i]);
    E[b[i]].push_back(a[i]);
    W[a[i]].push_back(w[i]);
    W[b[i]].push_back(w[i]);
  }

  dfs(0, -1);

  llint sum = 0;
  REP(i, n-1) {
    if (dad[a[i]] == b[i]) swap(a[i], b[i]);
    sum += llint(w[i]) * sz[b[i]] * (n - sz[b[i]]);
  }
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    int id, nw;
    scanf("%d %d", &id, &nw);
    --id;

    sum += llint(nw - w[id]) * sz[b[id]] * (n - sz[b[id]]);
    
    double ans = sum * 6.0 / n / (n-1);
    printf("%.9lf\n", ans);
    w[id] = nw;
  }
        
  return 0;
}