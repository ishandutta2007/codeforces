#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100010;

vector<int> E[MAXN];
int a[MAXN];
int init[MAXN], goal[MAXN];

vector<int> ans;

void dfs(int x, int dad, int fnow, int fnext) {
  if (a[x] != fnow) fnow ^= 1, ans.push_back(x);
  for (int y: E[x])
    if (y != dad) dfs(y, x, fnext, fnow);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  REP(i, n) scanf("%d", init+i);
  REP(i, n) scanf("%d", goal+i);
  REP(i, n) a[i] = init[i]^goal[i];

  dfs(0, -1, 0, 0);
  printf("%d\n", (int)ans.size());
  for (int y: ans) printf("%d\n", y+1);
  return 0;
}