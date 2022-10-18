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

using namespace std;

typedef long long llint;

const int MAX = 200100;

int n, m;

bool color[MAX];
bool bio[MAX];
int x[MAX], y[MAX];

set<int> X[MAX], Y[MAX];

void dfs(int i, bool dir, bool col) {
  bio[i] = true;
  color[i] = col;
  
  X[x[i]].erase(i);
  Y[y[i]].erase(i);

  if (dir) {
    if (X[x[i]].size()) dfs(*X[x[i]].begin(), dir ^ 1, col ^ 1);
  } else {
    if (Y[y[i]].size()) dfs(*Y[y[i]].begin(), dir ^ 1, col ^ 1);
  }
}

int main( void ) {
  scanf("%d", &n);
  
  REP(i, n) {
    scanf("%d %d", x+i, y+i);
    X[x[i]].insert(i);
    Y[y[i]].insert(i);
  }
  
  REP(i, n) {
    if (bio[i]) continue;
    dfs(i, false, false);
    dfs(i, true, false);
  }

  REP(i, n) putchar(color[i] ? 'b' : 'r');
  puts("");
  return 0;
}