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

const int MAXN = 300300;

vector<int> E[MAXN];
int c[MAXN];
int sz[MAXN];
char s[MAXN];

int t[MAXN][26];
int root, alloc = 1;

void dfs(int x, int dad) {
  sz[x] = 1;
  for (int y: E[x])
    if (y != dad) {
      dfs(y, x);
      sz[x] += sz[y];
    }
}

int newnode() {
  REP(i, 26) t[alloc][i] = 0;
  return alloc++;
}

void init() {
  alloc = 1;
  root = newnode();
}

void go(int x, int dad, int r) {
  if (t[r][s[x]] == 0) t[r][s[x]] = newnode();
  r = t[r][s[x]];
  for (int y: E[x])
    if (y != dad) go(y, x, r);
}

void solve(int x, int dad) {
  init();
  
  int m = -1;
  for (int y: E[x])
    if (y != dad) {
      if (m == -1 || sz[y] > sz[m]) m = y;
    }

  for (int y: E[x])
    if (y != dad && y != m) solve(y, x);
  if (m != -1) solve(m, x);
  for (int y: E[x])
    if (y != m && y != dad) go(y, x, root);

  int nroot = newnode();
  t[nroot][s[x]] = root;
  root = nroot;

  c[x] += alloc - 2;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &c[i]);
  scanf("%s", s);
  REP(i, n) s[i] -= 'a';

  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);
  solve(0, -1);

  int maks = *max_element(c, c + n);
  int cnt = count(c, c + n, maks);
  printf("%d %d\n", maks, cnt);
  return 0;
}