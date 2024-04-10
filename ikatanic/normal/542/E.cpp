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

const int MAX = 1010;
const int inf = 1e6;

vector<int> E[MAX];

vector<int> v;
bool bio[MAX];
bool bio2[MAX];
int bio3[MAX], cookie;

void dfs(int x) {
  if (bio[x]) return;
  bio[x] = true;
  v.push_back(x);
  for (int y: E[x]) dfs(y);
}

int solve(int x) {
  v.clear();
  dfs(x);
  
  int ans = -inf;
  for (int x: v) {
    for (int y: v) bio2[y] = false;
    bio2[x] = true;

    static vector<int> w, nw; w.clear();
    w.push_back(x);

    bool ok = true;
    int cnt = 0;
    while (w.size()) {
      nw.clear();
      cookie++;
      for (int x: w) bio3[x] = cookie;

      for (int x: w)
        for (int y: E[x]) {
          if (bio3[y] == cookie) { ok = false; break; }
          if (!bio2[y]) nw.push_back(y), bio2[y] = true;
        }
      
      if (!ok) break;
      
      w = nw;
      cnt++;
    }
    
    if (ok) {
      for (int y: v) assert(bio2[y]);
      ans = max(ans, cnt-1);
    }
  }

  return ans;
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
  
  int ans = 0;
  REP(i, n)
    if (!bio[i]) ans += solve(i);
  
  if (ans < 0) ans = -1;
  printf("%d\n", ans);
  return 0;
}