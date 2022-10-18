#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

vector<int> E[111111];

bool dfs(int x, int dad, int color, vector<int>& c) {
  if (c[x] != color) return false;
  for (int y: E[x])
    if (y != dad) {
      if (!dfs(y, x, color, c)) return false;
    }
  return true;
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  vector<int> c(n);
  REP(i, n) scanf("%d", &c[i]);

  int x = -1, y = -1;
  REP(i, n) for (int j: E[i]) {
    if (c[i] != c[j]) {
      x = i, y = j;
    }
  }

  if (x == -1) {
    puts("YES\n1\n");
    return 0;
  }

  for (int root : {x, y}) {
    bool ok = true;
    for (int y: E[root])
      ok &= dfs(y, root, c[y], c);
    
    if (ok) {
      printf("YES\n%d\n", root+1);
      return 0;
    }
  }

  puts("NO");
  return 0;
}