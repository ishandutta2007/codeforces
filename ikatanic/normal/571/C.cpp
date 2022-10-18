#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 400400;

vector<int> E[MAX];
int v[MAX][2];
int val[MAX];
int n, m;

bool dead[MAX];
int deg[MAX];

enum Color {WHITE, GRAY, BLACK};
Color color[MAX];
int disc[MAX];
int tick;

void direct(int x, int y) {
  if (x >= n) {
    if (dead[x]) return;
    val[x] = v[x][1] == y;
    dead[x] = dead[y] = true;
  } else {
    if (dead[y]) return;
    val[y] = v[y][1] != x;
    dead[y] = true;
    int nx = v[y][0] ^ v[y][1] ^ x;
    if (nx != -1) dead[nx] = true;
  }
}

int dfs(int x, int dad) {
  disc[x] = tick++;
  color[x] = GRAY;
  int lw = disc[x];

  for (int y: E[x]) {
    if (y == dad) continue;
    if (color[y] == BLACK) continue;

    if (color[y] == GRAY) {
      direct(x, y);
      lw = min(lw, disc[y]);
    } else {
      int lwy = dfs(y, x);
      if (lwy <= disc[x]) direct(x, y);
      lw = min(lw, lwy);
    }
  }

  color[x] = BLACK;
  return lw;
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, m) v[n+i][0] = v[n+i][1] = val[n+i] = -1;

  REP(i, n) {
    int k;
    scanf("%d", &k);
    REP(j, k) {
      int x;
      scanf("%d", &x);
      if (x > 0) {
        x = x-1 + n;
        E[i].push_back(x);
        E[x].push_back(i);
        v[x][1] = i;
      } else {
        x = -x-1 + n;
        E[i].push_back(x);
        E[x].push_back(i);
        v[x][0] = i;
      }
    }
  }

  REP(i, n+m) {
    sort(E[i].begin(), E[i].end());
    E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
  }

  FOR(x, n, n+m)
    if (E[x].size() == 2)
      if (v[x][0] == -1 || v[x][1] == -1) {
        dead[x] = dead[E[x][0]] = dead[E[x][1]] = true;
        val[x] = v[x][1] != -1;
      }

  REP(i, n+m)
    if (color[i] == WHITE) dfs(i, -1);

  queue<int> Q;
  REP(i, n+m)
    if (!dead[i]) {
      for (int y: E[i])
        deg[i] += !dead[y];
      if (deg[i] == 1) Q.push(i);
    }

  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    int y = -1;

    for (int Y: E[x])
      if (!dead[Y]) {
        assert(y == -1);
        y = Y;
      }
    if (y == -1) continue;

    int var = max(x, y);
    int cls = min(x, y);
    direct(var, cls);
    dead[var] = dead[cls] = true;
    
    for (int y: E[var])
      if (!dead[y]) {
        --deg[y];
        if (deg[y] == 1) Q.push(y);
      }

    for (int y: E[cls])
      if (!dead[y]) {
        --deg[y];
        if (deg[y] == 1) Q.push(y);
      }
  }

  REP(i, n)
    if (!dead[i]) {
      puts("NO");
      return 0;
    }

  puts("YES");
  REP(i, m)
    printf("%d", val[n+i] == 1);
  putchar('\n');
  return 0;
}