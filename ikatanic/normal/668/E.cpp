#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <bitset>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 2000;

vector<int> E[MAX];
bool stk[MAX];
int disc[MAX];
int n, t;

stack<int> S;
  
vector<vector<int>> comps;

int tarjan(int x) {
  int lw = disc[x] = ++t;
  
  stk[x] = true;
  S.push(x);
  
  for (int y: E[x])
    if (disc[y] == 0) lw = min(lw, tarjan(y)); else
      if (stk[y]) lw = min(lw, disc[y]);
  
  if (lw == disc[x]) {
    vector<int> comp;
    while (!S.empty()) {
      int y = S.top(); S.pop();
      comp.push_back(y);
      stk[y] = false;
      if (y == x) break;
    }
    comps.push_back(comp);
  }
  return lw;
}

bool visited[MAX];
bitset<MAX> f[MAX];
bool e[MAX][MAX];
int m;

void visit(int x) {
  if (visited[x]) return;
  visited[x] = true;
  f[x].reset();
  for (int v: comps[x]) f[x].set(v);
  REP(y, m)
    if (e[x][y]) {
      visit(y);
      f[x] |= f[y];
    }
}

int main(void) {
  int m1, m2;
  scanf("%d %d %d", &n, &m1, &m2);

  vector<pair<int, int>> A, B;
  auto encode = [&] (int x) {
    if (x < 0) return 2*(-x - 1);
    return 2*(x - 1) + 1;
  };

  REP(i, m1) {
    int x, y;
    scanf("%d %d", &x, &y);
    A.push_back({encode(x), encode(y)});
  }
  REP(i, m2) {
    int x, y;
    scanf("%d %d", &x, &y);
    B.push_back({encode(x), encode(y)});
  }
  
  REP(it, 2) {
    REP(i, 2*n) {
      disc[i] = 0;
      stk[i] = false;
      E[i].clear();
    }
    comps.clear();

    for (auto&p : A) {
      E[p.first ^ 1].push_back(p.second);
      E[p.second ^ 1].push_back(p.first);
    }
    
    REP(i, 2*n)
      if (!disc[i]) tarjan(i);
    
    static int compId[MAX];
    m = comps.size();
    REP(i, m) for (int x: comps[i])
      compId[x] = i;

    REP(i, 2*n) REP(j, 2*n) e[i][j] = false;
    REP(x, 2*n)
      for (int y: E[x])
        if (compId[x] != compId[y]) e[compId[x]][compId[y]] = true;

    REP(i, m) visited[i] = false;
    REP(i, m) visit(i);

    bitset<MAX> must;
    must.reset();
    REP(i, 2*n)
      if (f[compId[i]].test(i^1)) must.set(i^1);
    bitset<MAX> even;
    REP(i, 2*n) if (i % 2 == 0) even.set(i);

    for (auto& p: B) {
      bitset<MAX> tmp;
      tmp = must | f[compId[p.first ^ 1]] | f[compId[p.second ^ 1]];
      tmp = (tmp >> 1) & tmp & even;
      if (!tmp.any()) {
        tmp = must | f[compId[p.first ^ 1]] | f[compId[p.second ^ 1]];
        REP(i, n) {
          if (!tmp.test(2*i) && !tmp.test(2*i + 1)) tmp |= f[compId[2*i]];
          printf("%d ", tmp.test(2*i + 1));
        }
        puts("");
        return 0;
      }
    }

    A.swap(B);
  }
  
  puts("SIMILAR");
  return 0;
}