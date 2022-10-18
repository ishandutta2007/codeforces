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

const int MAX = 200200;

vector<int> E[MAX];
enum Color {WHITE, GRAY, BLACK};

Color color[MAX];
vector<vector<int>> ret;

bool dfs(int x, int dad) {
  color[x] = GRAY;
  vector<int> edges;
  for (int y: E[x]) {
    if (y == dad) continue;
    if (color[y] == WHITE) {
      bool done = dfs(y, x);
      if (!done) {
        edges.push_back(y);
      }
    } else if (color[y] == GRAY) {
      edges.push_back(y);
    }
  }
  color[x] = BLACK;

  while (edges.size() >= 2) {
    int a = edges.back(); edges.pop_back();
    int b = edges.back(); edges.pop_back();
    ret.push_back({a, x, b});
  }

  if (edges.size() == 1) {
    if (dad != -1) {
      ret.push_back({edges[0], x, dad});
      return true;
    }
  }
  return false;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  REP(i, n) {
    if (color[i] == WHITE) {
      dfs(i, -1);
    }
  }
  
  printf("%d\n", (int)ret.size());
  for (auto& p: ret) printf("%d %d %d\n", p[0]+1, p[1]+1, p[2]+1);
  return 0;
}