#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;
const int LG = 18;
const int K = 10;

int L[MAX][LG];
int dep[MAX];
vector<int> V[MAX][LG];
vector<int> E[MAX];

vector<int> operator+(const vector<int>& a, const vector<int>& b) {
  vector<int> c;
  auto ita = a.begin();
  auto itb = b.begin();
  while (c.size() < K && (ita != a.end() || itb != b.end())) {
    if (ita != a.end() && (itb == b.end() || *ita < *itb)) c.push_back(*ita++); else {
      if (ita != a.end() && *ita == *itb) ita++;
      c.push_back(*itb++);
    }
  }
  return c;
}

void dfs(int x, int dad) {
  L[x][0] = dad;
  for (int y: E[x])
    if (y != dad) {
      dep[y] = dep[x] + 1;
      dfs(y, x);
    }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int j = LG-1; j >= 0; --j)
    if (dep[u] - (1<<j) >= dep[v]) u = L[u][j];
  if (u == v) return u;
  for (int j = LG-1; j >= 0; --j)
    if (L[u][j] != L[v][j]) u = L[u][j], v = L[v][j];
  return L[u][0];
}

int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, 0);
  REP(i, m) {
    int x;
    scanf("%d", &x); --x;
    V[x][0].push_back(i);
  }

  FOR(j, 1, LG) REP(i, n) {
    L[i][j] = L[L[i][j-1]][j-1];
    V[i][j] = V[i][j-1] + V[L[i][j-1]][j-1];
  }
  
  REP(i, q) {
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k); --u, --v;

    int l = lca(u, v);
    vector<int> ans = V[l][0];
    for (int j = LG-1; j >= 0; --j) {
      if (dep[L[u][j]] >= dep[l]) {
        ans = ans + V[u][j];
        u = L[u][j];
      }
      if (dep[L[v][j]] >= dep[l]) {
        ans = ans + V[v][j];
        v = L[v][j];
      }
    }

    k = min(k, (int)ans.size());
    printf("%d", k);
    REP(j, k) printf(" %d", ans[j]+1);
    printf("\n");
  }
  return 0;
}