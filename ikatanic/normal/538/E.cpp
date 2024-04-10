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

const int MAX = 200100;

vector<int> E[MAX];

int fm[MAX];
int fM[MAX];
int m[MAX];

void dfs(int x, int dad, int who) {
  for (int y: E[x])
    if (y != dad) {
      dfs(y, x, who^1);
      m[x] += m[y];
    }
  
  if (m[x] == 0) {
    m[x] = 1;
    fm[x] = fM[x] = 0;
    return;
  }
  
  if (who == 0) {
    int sum = 0, best = MAX;
    for (int y: E[x])
      if (y != dad) {
        best = min(best, m[y] - fM[y]);
        sum += m[y] - fm[y] - 1;
      }

    fM[x] = m[x] - best;
    fm[x] = m[x] - sum - 1;
  } else {
    int sum = 0, best = MAX;
    for (int y: E[x])
      if (y != dad) {
        sum += fM[y];
        best = min(best, fm[y]);
      }
    
    fM[x] = sum;
    fm[x] = best;
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a; --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1, 0);
  printf("%d %d\n", fM[0]+1, fm[0]+1);
  return 0;
}