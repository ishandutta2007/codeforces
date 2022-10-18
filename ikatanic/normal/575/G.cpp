#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100010;

struct Edge {
  int b, w;
};

vector<Edge> E[MAX];
bool bio[MAX];
int d[MAX], par[MAX];
int ds[MAX], par2[MAX];
int n;

void bfs(int start, int *d, int *par, int lim) {
  REP(i, n) d[i] = -1;
  d[start] = 0;
  queue<int> Q;
  Q.push(start);
  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    for (Edge& e: E[x])
      if (d[e.b] == -1)
        if (e.w <= lim) {
          par[e.b] = x;
          d[e.b] = d[x] + 1;
          Q.push(e.b);
        }
  }
}

vector<vector<int>> l;
vector<int> pars[MAX];
bool good[MAX];

int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  int s = n-1, t = 0;
  bfs(t, d, par, 9);
  bfs(s, ds, par2, 0);

  assert(d[s] != -1);
  l.resize(d[s] + 1);

  int best = d[s];
  REP(i, n)
    if (ds[i] != -1) best = min(best, d[i]);
  REP(i, n)
    if (ds[i] != -1 && best == d[i]) l[best].push_back(i);

  string cost = "";
  for (int i = best; i > 0; --i) {
    int ne = 10;
    for (int x: l[i])
      for (Edge& e: E[x])
        if (d[e.b] == i - 1) ne = min(ne, e.w);
    assert(ne < 10);
    cost.push_back('0' + ne);
    for (int x: l[i])
      for (Edge& e: E[x])
        if (d[e.b] == i - 1 && ne == e.w) {
          if (pars[e.b].size() == 0) l[i-1].push_back(e.b);
          pars[e.b].push_back(x);
        }
  }

  for (int x: l[0]) good[x] = true;
  for (int i = 0; i < best; ++i)
    for (int x: l[i])
      for (int y: pars[x])
        good[y] |= good[x];

  int start = -1;
  for (int x: l[best])
    if (good[x])
      if (start == -1 || ds[x] < ds[start]) start = x;
  assert(start != -1);

  vector<int> path = {start};
  int cur = start;
  for (int i = best; i > 0; --i) {
    int next = -1;
    for (Edge& e: E[cur])
      if (d[e.b] == i-1 && e.w == cost[best-i]-'0')
        if (good[e.b]) next = e.b;
    assert(next != -1);
    cur = next;
    path.push_back(cur);
  }
  reverse(path.begin(), path.end());

  while (start != s) {
    path.push_back(par2[start]);
    start = par2[start];
  }

  if (cost == "") cost = "0";
  puts(cost.c_str());
  printf("%d\n", (int)path.size());
  for (int x: path) printf("%d ", x);
  printf("\n");
  return 0;
}