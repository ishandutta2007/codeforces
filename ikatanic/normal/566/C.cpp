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

const int MAX = 200200;
const double eps = 1e-9;

struct Edge {
  int b, w;
};

vector<Edge> E[MAX];
bool dead[MAX];
int w[MAX];
int bal[MAX], sz[MAX];
vector<int> v;

void dfs(int x, int dad) {
  v.push_back(x);
  bal[x] = 0;
  sz[x] = 1;
  for (Edge& e: E[x])
    if (e.b != dad && !dead[e.b]) {
      dfs(e.b, x);
      bal[x] = max(bal[x], sz[e.b]);
      sz[x] += sz[e.b];
    }
}

void calc(int x, int dad, double& der, double& total, int dist) {
  double sq = sqrt(dist) * w[x];
  der += sq;
  total += sq * dist;
  for (Edge& e: E[x])
    if (e.b != dad)
      calc(e.b, x, der, total, dist + e.w);
}

void solve(int x) {
  v.clear();
  dfs(x, -1);
  for (int x: v)
    bal[x] = max(bal[x], (int)v.size() - sz[x]);
  for (int y: v)
    if (bal[y] < bal[x]) x = y;

  assert(2*bal[x] <= (int)v.size());
  dead[x] = true;

  double total = 0, totalder = 0, maks = 0;
  int id = -1;
  for (Edge& e: E[x]) {
    double der = 0;
    calc(e.b, x, der, total, e.w);
    totalder += der;
    if (id == -1 || der > maks) {
      maks = der;
      id = e.b;
    }
  }
  
  if (id == -1 || dead[id] || totalder-2*maks > -eps) {
    if (id != -1) {
      double der2 = 0, total2 = 0;
      for (Edge& e: E[id])
        calc(e.b, id, der2, total2, e.w);
      if (total2 < total) total = total2, x = id;
    }
    printf("%d %.10lf\n", x+1, total);
    exit(0);
  }

  solve(id);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", w+i);
  REP(i, n-1) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w); --a, --b;
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  solve(0);
  assert(false);
  return 0;
}