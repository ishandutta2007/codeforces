#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 1000100;

int d[MAXN];
int LCA[MAXN][20];
int n, a, b, len;

int dist(int x, int y) {
  int ans = d[x] + d[y];
  if (d[x] < d[y]) swap(x, y);
  for (int j = 19; j >= 0; --j)
    if (d[x]-(1<<j) >= d[y]) x = LCA[x][j];
  
  if (x != y) {
    for (int j = 19; j >= 0; --j)
      if (LCA[x][j] != LCA[y][j]) x = LCA[x][j], y = LCA[y][j];
    x = LCA[x][0], y = LCA[y][0];
  }
  ans -= 2*d[x];
  return ans;
}

void add(int x, bool update) {
  int y = n++;
  d[y] = d[x] + 1;
  LCA[y][0] = x;
  for (int j = 1; j < 20; ++j)
    LCA[y][j] = LCA[LCA[y][j-1]][j-1];
  
  if (update) {
    if (dist(a, y) > len) b = y, len++; else
      if (dist(b, y) > len) a = y, len++;
  }
}

int main(void)
{
  n = 1;
  d[0] = 0;
  
  add(0, false);
  add(0, false);
  add(0, false);
  
  a = 1, b = 2, len = 2;

  int q;
  scanf("%d", &q);
  REP(i, q) {
    int x;
    scanf("%d", &x); --x;
    add(x, true);
    add(x, false);
    printf("%d\n", len);
  }
  return 0;
}