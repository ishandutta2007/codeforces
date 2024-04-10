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

const int MAXN = 200500;

vector<int> E[MAXN];

int a[MAXN], k[MAXN];
int d[MAXN], f[MAXN];

int tick = 0;
void dfs(int x, int dad, int koef){
  d[x] = tick++;
  k[x] = koef;
  for (int y: E[x])
    if (y != dad) dfs(y, x, -koef);
  f[x] = tick;
}

struct Loga {
  int L[MAXN];
  
  void add(int x, int y) {
    for (++x; x < MAXN; x += x&-x)
      L[x] += y;
  }

  int sum(int x) {
    int ans = 0;
    for (++x; x; x -= x&-x)
      ans += L[x];
    return ans;
  }

  int sum(int x, int y) {
    return sum(y) - sum(x-1);
  }
} L;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, n-1) {
    int x, y;
    scanf("%d %d", &x, &y); --x, --y;
    E[x].push_back(y);
    E[y].push_back(x);
  }

  dfs(0, -1, 1);
  REP(i, m) {
    int tip;
    scanf("%d", &tip);
    if (tip == 1) {
      int x, val;
      scanf("%d %d", &x, &val); --x;
      val *= k[x];
      L.add(d[x], val);
      L.add(f[x], -val);
    } else {
      int x;
      scanf("%d", &x); --x;
      printf("%d\n", a[x] + k[x]*L.sum(d[x]));
    }
  }

  return 0;
}