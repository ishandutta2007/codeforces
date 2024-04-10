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

const int MAXN = 100100;

vector<int> E[MAXN];
vector<int> F[MAXN];
int p[MAXN];

vector<int> ans;
int dad[MAXN];
bool bio[MAXN];

bool dfs(int x) {
  bio[x] = true;
  bool ans = p[x];
  for (int y: E[x])
    if (!bio[y]) {
      F[x].push_back(y);
      dad[y] = x;
      ans |= dfs(y);
    }
  return ans;
}

void visit(int x) {
  p[x] ^= 1;
  ans.push_back(x+1);
}

void solve(int x) {
  for (int y: F[x]) {
    visit(y);
    solve(y);
    visit(x);
  }
  
  if (p[x]) {
    if (dad[x] != -1) {
      visit(dad[x]);
      visit(x);
    } else {
      assert(F[x].size());
      visit(F[x][0]);
      visit(x);
      visit(F[x][0]);
    }
  }
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }  
  REP(i, n) scanf("%d", p+i);
  
  REP(i, n)
    if (!bio[i]) {
      dad[i] = -1;
      if (!dfs(i)) continue;
      if (ans.size()) {
        puts("-1");
        return 0;
      }
      visit(i);
      solve(i);
    }

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}