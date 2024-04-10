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

const int MAX = 202000;

vector<int> E[MAX];
bool u[MAX];
int cu[MAX];

void dfs(int x, int dad) {
  cu[x] = u[x];
  for (int y: E[x])
    if (y != dad) {
      dfs(y, x);
      cu[x] += cu[y];
    }
}

llint solve(int x, int dad, int need_pairs) {
  if (cu[x] == 0) {
    assert(need_pairs == 0);
    return 0;
  }

  vector<int> c;
  if (u[x]) c.push_back(1);
  for (int y: E[x])
    if (y != dad) c.push_back(cu[y]);
  
  int maks = *max_element(c.begin(), c.end());
  int sum = cu[x];

  int can_pairs = min(sum / 2, sum - maks);

  if (can_pairs >= need_pairs) {
    llint ans = 0;
    for (int y: E[x])
      if (y != dad) ans += solve(y, x, 0) + cu[y];
    return ans;
  } else {
    llint ans = 0;
    for (int y: E[x])
      if (y != dad) {
        if (cu[y] == maks) {
          ans += solve(y, x, need_pairs - can_pairs) + maks - (need_pairs - can_pairs)*2;
        } else {
          ans += solve(y, x, 0) + cu[y];
        }
      }
    return ans;
  }
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, 2*k) {
    int x;
    scanf("%d", &x); --x;
    u[x] = true;
  }

  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);
  printf("%lld\n", solve(0, -1, k));
  return 0;
}