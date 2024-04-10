#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 3030;

vector<int> E[MAXN], C[MAXN];
int sum[MAXN], sz[MAXN];

bool bio[MAXN];
int a[MAXN];
int n;

void dfs(int x, int c, int m) {
  bio[x] = true;
  sz[c]++, sum[c] += a[x];
  REP(i, (int)E[x].size())
    if (!bio[E[x][i]] && C[x][i] < m)
      dfs(E[x][i], c, m);
}

bool can(int m) {
  REP(i, n) bio[i] = false;
  REP(i, n) sz[i] = sum[i] = 0;
  int c = 0;
  REP(i, n)
    if (!bio[i]) dfs(i, c++, m);
  
  int tot = 0;
  REP(i, c) tot += sum[i];
  REP(i, c)
    if (sz[i] > tot-sum[i]) return false;
  return true;
}
  
int main(void) {
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c); --a, --b;
    E[a].push_back(b);
    C[a].push_back(c);
    E[b].push_back(a);
    C[b].push_back(c);
  }
  REP(i, n) scanf("%d", a+i);

  int lo = 0, hi = 20000;
  while (lo < hi) {
    int mid = (lo + hi + 1)/2;
    if (can(mid)) lo = mid; else
      hi = mid-1;
  }
  printf("%d\n", lo);
  return 0;
}