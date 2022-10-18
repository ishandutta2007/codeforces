#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;

const int MAXN = 100100;

vector<int> E[MAXN];
int color[MAXN];
enum {W, G, B};

bool solve(int x, int dad) {
  color[x] = G;

  int first = -1;
  auto add = [&x, &first] (int y) {
    if (first == -1) first = y; else {
      printf("%d %d %d\n", first+1, x+1, y+1);
      first = -1;
    }
  };
    
  for (int y: E[x])
    if (y != dad) {
      if (color[y] == W) {
        if (!solve(y, x)) add(y);
      } else
        if (color[y] == G)
          add(y);
    }

  color[x] = B;
  if (first != -1) {
    add(dad);
    return true;
  }
  return false;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    E[x].push_back(y);
    E[y].push_back(x);
  }

  if (m%2) {
    puts("No solution");
    return 0;
  }
  
  solve(0, -1);
  return 0;
}