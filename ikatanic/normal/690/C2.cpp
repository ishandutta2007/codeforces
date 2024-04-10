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

const int MAX = 101000;

int d[MAX];
vector<int> E[MAX];
int n;

pair<int, int> dfs(int x, int dad) {
  int m1 = 0, m2 = 0;
  int ans = 0;
  for (int y: E[x]) {
    if (y == dad) continue;
    
    auto p = dfs(y, x);
    p.second++;
    ans = max(ans, p.first);
    if (p.second >= m1) {
      m2 = m1;
      m1 = p.second;
    } else if (p.second > m2) m2 = p.second;
  }

  ans = max(ans, m1 + m2);
  return {ans, m1};
}

int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  printf("%d\n", dfs(0, -1).first);
  return 0;
}