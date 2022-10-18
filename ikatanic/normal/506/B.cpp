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

const int MAXN = 100010;

vector<int> E[MAXN];
int bio[MAXN], disc[MAXN], t;
int color[MAXN];
bool found_cycle;

enum {WHITE, GRAY, BLACK};

void dfs(int x) {
  color[x] = GRAY;
  for (int y: E[x])
    if (color[y] == GRAY) found_cycle = true; else
      if (color[y] == WHITE) dfs(y);
  color[x] = BLACK;
}

vector<int> F[MAXN];

vector<int> v;
void dfs2(int x) {
  if (bio[x]) return;
  bio[x] = true;
  v.push_back(x);
  for (int y: F[x])
    dfs2(y);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    F[a].push_back(b);
    F[b].push_back(a);
  }

  int ans = 0;
  
  REP(i, n)
    if (F[i].size() && !bio[i]) {
      v.clear();
      dfs2(i);
      
      found_cycle = false;
      for (int x: v)
        if (color[x] == WHITE) dfs(x);

      ans += v.size()-1 + (int)found_cycle;
    }

  printf("%d\n", ans);
  return 0;
}