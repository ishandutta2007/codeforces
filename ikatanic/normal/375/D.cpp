#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100100;

vector<int> Q[MAXN], E[MAXN];

int sz[MAXN];
int c[MAXN];
int v[MAXN], k[MAXN];
int ans[MAXN];

int M[50][MAXN];
int H[50][MAXN];
set<int> S[50];
set<int> SK[50];

bool busy[50];

void dfs(int x, int dad) {
  sz[x] = 1;
  for (int y : E[x])
    if (y != dad) {
      dfs(y, x);
      sz[x] += sz[y];
    }
}

int getNewArray() {
  REP(i, 50)
    if (!busy[i]) {
      busy[i] = true;
      return i;
    }
}

void freeArray(int f) {
  busy[f] = false;
  for (int boja : S[f]) M[f][boja] = 0;
  for (int k : SK[f]) H[f][k] = 0;
  S[f].clear(), SK[f].clear();
}

void dodaj(int f, int boja, int k) {
  int K = M[f][boja];

  if (K > 0) {
    --H[f][K];
    if (H[f][K] == 0) SK[f].erase(K);
  }

  K = M[f][boja] += k;
  
  H[f][K]++;
  if (H[f][K] == 1) SK[f].insert(K);
  S[f].insert(boja);
}

int solve(int x, int dad) {
  int m = -1;
  for (int y : E[x])
    if (y != dad) {
      if (m == -1 || sz[y] > sz[m]) m = y;
    }
  
  int f = -1;
  if (m != -1) f = solve(m, x); else
    f = getNewArray();
  
  for (int y : E[x])
    if (y != dad && y != m) {
      int fy = solve(y, x);
      for (int boja : S[fy]) 
        dodaj(f, boja, M[fy][boja]);
      freeArray(fy);
    }
  
  dodaj(f, c[x], 1);

  for (int K : SK[f])
    for (int q : Q[x]) 
      if (k[q] <= K) ans[q] += H[f][K];
  return f;
}

int main(void)
{
  int n, q;
  scanf("%d %d", &n, &q);
  REP(i, n) scanf("%d", c+i);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  REP(i, q) {
    scanf("%d %d", v+i, k+i); --v[i];
    Q[v[i]].push_back(i);
  }

  dfs(0, -1);
  solve(0, -1);
  
  REP(i, q) printf("%d\n", ans[i]);
  return 0;
}