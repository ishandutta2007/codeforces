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

const int MAX = 1000100;
const int LG = 20;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a < b ? a-b+mod : a-b;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int L[MAX][LG];

struct Edge {
  int b, w;
};

vector<Edge> E[MAX];
int dad[MAX], dir[MAX], dep[MAX];
int n;

void dfs(int x) {
  for (auto& e: E[x]) {
    if (e.b == dad[x]) {
      if (e.w) dir[x] |= 2;
      continue;
    }
    dad[e.b] = x;
    dir[e.b] = e.w;
    dep[e.b] = dep[x] + 1;
    dfs(e.b);
  }
}

void initLCA() {
  REP(i, n) L[i][0] = dad[i];
  FOR(j, 1, LG) REP(i, n)
    L[i][j] = L[ L[i][j-1] ][j-1];
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

int sd[MAX], su[MAX];

void inc(int a, int b) {
  if (dep[a] > dep[b]) { // up
    su[a]++, su[b]--;
  } else { // down
    sd[b]++, sd[a]--;
  }
}

void dfs2(int x) {
  for (Edge& e: E[x]) {
    if (dad[x] == e.b) continue;
    dfs2(e.b);
    sd[x] += sd[e.b];
    su[x] += su[e.b];
  }
}

int main(void) {
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x); --a, --b;
    E[a].push_back({b, 1});
    E[b].push_back({a, !x});
  }

  dad[0] = -1;
  dfs(0);
  initLCA();

  int k;
  scanf("%d", &k);

  int last = 0;
  REP(i, k) {
    int next;
    scanf("%d", &next); --next;
    
    int l = lca(last, next);
    inc(last, l);
    inc(l, next);
    last = next;
  }

  dfs2(0);

  static int pw2[MAX];
  pw2[0] = 1;
  REP(i, MAX-1) pw2[i + 1] = mul(pw2[i], 2);

  int ans = 0;
  FOR(i, 1, n) {
    if (dir[i] == 1) { // up is illegal
      ans = add(ans, sub(pw2[su[i]], 1));
    }
    if (dir[i] == 2) { // down is illegal
      ans = add(ans, sub(pw2[sd[i]], 1));
    }
  }

  printf("%d\n", ans);
  return 0;
}