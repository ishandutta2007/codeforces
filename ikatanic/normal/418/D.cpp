#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;
const int MAXLG = 20;
const int inf = 1e9;

int f[MAXN][MAXLG];
int g[MAXN][MAXLG];
int L[MAXN][MAXLG];

vector<int> E[MAXN];
int d[MAXN], dad[MAXN];
int up[MAXN], maxd[MAXN];

multiset<int, greater<int>> S[MAXN];

int getMostDistant(int x, int ignore1, int ignore2) {
  if (ignore1 < ignore2) swap(ignore1, ignore2);

  auto it = S[x].begin();
  if (*it == ignore1) {
    ++it;
    if (*it == ignore2) ++it;
  } else
    if (*it == ignore2) ++it;

  return *it;
}

void dfs(int x) {
  S[x].insert(0);
  for (int y: E[x])
    if (y != dad[x]) {
      d[y] = d[x] + 1, dad[y] = x;
      dfs(y);
      S[x].insert(maxd[y] + 1);
    }
  maxd[x] = *S[x].begin();
}

void dfsup(int x) {
  S[x].insert(up[x]);
  for (int y: E[x])
    if (y != dad[x]) {
      up[y] = getMostDistant(x, maxd[y]+1, -1) + 1;
      dfsup(y);
    }
}

int climb(int x, int d) {
  for (int j = MAXLG-1; j >= 0; --j)
    if (d&(1<<j)) x = L[x][j];
  return x;
}

int getLca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  a = climb(a, d[a]-d[b]);
  if (a == b) return a;
  for (int j = MAXLG-1; j >= 0; --j)
    if (L[a][j] != L[b][j]) a = L[a][j], b = L[b][j];
  return dad[a];
}

int queryf(int x, int l) {
  int ans = 0, pos = 0;
  for (int j = MAXLG-1; j >= 0; --j)
    if (l&(1<<j)) {
      ans = max(ans, f[x][j] + pos);
      x = L[x][j];
      pos += (1<<j);
      if (x == -1) break;
    }
  return ans;
}

int queryg(int x, int l) {
  int ans = -inf;
  for (int j = MAXLG-1; j >= 0; --j)
    if (l&(1<<j)) {
      ans += (1<<j);
      ans = max(ans, g[x][j]);
      x = L[x][j];
      if (x == -1) break;
    }
  return ans;
}
  
int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  d[0] = 0, up[0] = 0, dad[0] = -1;
  dfs(0);
  dfsup(0);

  REP(i, n) {
    L[i][0] = dad[i];
    f[i][0] = g[i][0] = 0;
    if (dad[i] != -1) {
      g[i][0] = getMostDistant(dad[i], maxd[i]+1, up[dad[i]]);
      f[i][0] = 1 + g[i][0];
    }
  }

  for (int j = 1; j < MAXLG; ++j)
    REP(i, n) {
      L[i][j] = -1;
      f[i][j] = f[i][j-1];
      g[i][j] = g[i][j-1] + (1<<(j-1));
      if (L[i][j-1] != -1) {
        L[i][j] = L[ L[i][j-1] ][j-1];
        f[i][j] = max(f[i][j], f[ L[i][j-1] ][j-1] + (1<<(j-1)));
        g[i][j] = max(g[i][j], g[ L[i][j-1] ][j-1]);
      }
    }

  int m;
  scanf("%d", &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    if (d[a] < d[b]) swap(a, b);

    int ans = 0;
    
    int lca = getLca(a, b);
    int len = (d[a] + d[b] - 2*d[lca])/2;

    if (lca == b) {
      int lca_a = climb(a, d[a]-d[lca]-1);
      int mid = climb(a, len);
      
      ans = max(ans, getMostDistant(b, maxd[lca_a]+1, -1));
      ans = max(ans, maxd[a]);
      ans = max(ans, queryf(a, len));
      ans = max(ans, queryg(mid, d[mid]-d[lca]-1) + 1);
    } else {
      ans = max(ans, maxd[a]);
      ans = max(ans, maxd[b]);
      
      int lca_a = climb(a, d[a]-d[lca]-1);
      int lca_b = climb(b, d[b]-d[lca]-1);

      ans = max(ans, queryf(a, min(len, d[a]-d[lca]-1)));
      ans = max(ans, queryf(b, min(len, d[b]-d[lca]-1)));
      
      if (d[a]-len-1 > d[lca]) {
        int mid = climb(a, len);
        ans = max(ans, queryg(mid, d[mid]-d[lca]-1) + d[b]-d[lca]+1);
      } 
      
      ans = max(ans, getMostDistant(lca, maxd[lca_a]+1, maxd[lca_b]+1) + d[b]-d[lca]);
    }
    
    printf("%d\n", ans);
  }

  return 0;
}