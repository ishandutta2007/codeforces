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

const int MAXN = 200100;

vector<int> E[MAXN];
llint f[MAXN], g[MAXN];
int n, c1, c2;

void solve(int x, int dad) {
  vector<llint> v;
  llint total = 0;
  for (int y: E[x]) {
    if (y == dad) continue;
    solve(y, x);
    v.push_back(c1 - c2 + g[y] - f[y]);
    total += f[y];
  }
  total += (llint)v.size()*c2;

  sort(v.begin(), v.end());

  f[x] = g[x] = total;
  if (v.size() > 0) f[x] += v[0], g[x] += v[0];
  if (v.size() > 1) f[x] += v[1];
}

int main(void) {
  scanf("%d %d %d", &n, &c1, &c2);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  solve(0, -1);

  llint cost1 = llint(n-1)*c2;
  REP(i, n)
    if ((int)E[i].size() == n-1) { cost1 += c1 - c2; break; }
  llint ans = min(cost1, f[0]);
  printf("%lld\n", ans);
  return 0;
}