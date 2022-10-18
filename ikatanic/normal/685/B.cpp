#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 300300;

int sz[MAX];
int msz[MAX];
int p[MAX];
vector<int> E[MAX];
int ans[MAX];

set<pair<int, int>> S;
int n;

void dfs(int x) {
  S.insert({sz[x], x});
  auto it = S.lower_bound({2*msz[x], -1});
  while (it != S.end() && it->first <= 2*sz[x]) {
    ans[it->second] = x;
    auto tmp = it++;
    S.erase(tmp);
  }
  
  for (int y: E[x]) {
    dfs(y);
  }

  S.erase({sz[x], x});
}

void dfs1(int x) {
  sz[x] = 1;
  msz[x] = 0;
  for (int y: E[x]) {
    dfs1(y);
    sz[x] += sz[y];
    msz[x] = max(msz[x], sz[y]);
  }
}

int main(void) {
  int q;
  scanf("%d %d", &n, &q);
  FOR(i, 1, n) scanf("%d", &p[i]);
  FOR(i, 1, n) E[--p[i]].push_back(i);
  p[0] = -1;

  dfs1(0);
  dfs(0);

  REP(i, q) {
    int x;
    scanf("%d", &x); --x;
    printf("%d\n", ans[x]+1);
  }

  return 0;
}