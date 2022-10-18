#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100100;

vector<int> E[MAX];
int maxd[MAX]; // max path going from x
int maxc[MAX]; // max path in component
int comp_i[MAX];
vector<int> comp[MAX];
vector<int> compd[MAX];
vector<llint> compd_pref[MAX];
bool bio[MAX];

void dfs1(int x, int dad, int comp_id) {
  bio[x] = true;
  comp_i[x] = comp_id;
  comp[comp_id].push_back(x);
  
  int m1 = 0, m2 = 0;
  for (int y: E[x]) {
    if (y != dad) {
      dfs1(y, x, comp_id);
      if (maxd[y]+1 >= m1) m2 = m1, m1 = maxd[y]+1;
      else if (maxd[y]+1 >= m2) m2 = maxd[y]+1;
    }
  }
  maxc[comp_id] = max(maxc[comp_id], m1 + m2);
  maxd[x] = m1;
}

void dfs2(int x, int dad, int m) {
  maxd[x] = max(maxd[x], m);
  int m1 = 0, m2 = 0;
  for (int y: E[x]) {
    if (y != dad) {
      if (maxd[y]+1 >= m1) m2 = m1, m1 = maxd[y]+1;
      else if (maxd[y]+1 >= m2) m2 = maxd[y]+1;
    }
  }

  for (int y: E[x]) {
    if (y != dad) {
      if (maxd[y]+1 != m1) dfs2(y, x, max(m, m1)+1);
      else dfs2(y, x, max(m, m2)+1);
    }
  }
}

map<pair<int, int>, double> cache;

double solve(int a, int b) {
  if (a == b) return -1;
  if (comp[a].size() > comp[b].size()) swap(a, b);
  
  auto p = make_pair(a, b);
  if (cache.count(p)) return cache[p];

  llint ans = 0;
  int m = max(maxc[a], maxc[b]);
  
  for (int x: comp[a]) {
    // count pairs s.t. maxd[x] + maxd[y] + 1 >= m
    int i = lower_bound(compd[b].begin(), compd[b].end(), m - maxd[x] - 1) - compd[b].begin();

    llint cnt = compd[b].size() - i;
    llint sum = compd_pref[b].back() - compd_pref[b][i];

    ans += sum + (maxd[x] + 1) * cnt;
    ans += m * (comp[b].size() - cnt);
  }
  
  double ret = ans * 1.0 / comp[a].size() / comp[b].size();
  return cache[p] = ret;
}


int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  REP(i, n) {
    if (!bio[i]) {
      dfs1(i, -1, i);
      dfs2(i, -1, 0);

      for (int x: comp[i]) {
        compd[i].push_back(maxd[x]);
      }
      sort(compd[i].begin(), compd[i].end());
      compd_pref[i].resize(compd[i].size() + 1, 0);
      for (int j = 0; j < (int)compd[i].size(); ++j) {
        compd_pref[i][j + 1] = compd_pref[i][j] + compd[i][j];
      }
    }
  }

  REP(i, q) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;

    a = comp_i[a];
    b = comp_i[b];

    printf("%.10lf\n", solve(a, b));
  }
  
  return 0;
}