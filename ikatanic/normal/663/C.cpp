#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 202000;

vector<int> R[MAX];
vector<int> B[MAX];

vector<int> v, colored;
bool bio[MAX];
bool color[MAX];
bool ok;

void dfs(int x, int c) {
  if (bio[x]) {
    if (color[x] != c) ok = false;
    return;
  }

  bio[x] = true;
  color[x] = c;
  v.push_back(x);
  if (c) colored.push_back(x);

  for (int y: R[x]) dfs(y, c);
  for (int y: B[x]) dfs(y, c^1);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    char c[11];
    scanf("%d %d %s", &a, &b, c);
    --a, --b;
    if (c[0] == 'R') {
      R[a].push_back(b);
      R[b].push_back(a);
    } else {
      B[a].push_back(b);
      B[b].push_back(a);
    }
  }

  vector<int> ans;
  bool solved = false;
  REP(it, 2) {
    REP(i, n) bio[i] = false;
    vector<int> cur;
    bool allok = true;

    REP(i, n)
      if (!bio[i]) {
        vector<int> best;
        bool found = false;

        v.clear();
        colored.clear();
        ok = true;
        dfs(i, 0);
        if (ok) {
          if (!found || colored.size() < best.size()) best = colored, found = true;
        }
        
        for (int x: v) bio[x] = false;
        ok = true;
        v.clear();
        colored.clear();
        dfs(i, 1);
        if (ok) {
          if (!found || colored.size() < best.size()) best = colored, found = true;
        }
        
        if (!found) {
          allok = false;
          break;
        }

        for (int x: best) cur.push_back(x);
      }
    
    if (allok) {
      if (!solved || cur.size() < ans.size()) solved = true, ans = cur;
    }
    REP(i, n) R[i].swap(B[i]);
  }

  if (!solved) puts("-1");
  else {
    printf("%d\n", (int)ans.size());
    for (int x: ans) printf("%d ", x+1);
    printf("\n");
  }
    
  return 0;
}