#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1<<17;

int deg[MAXN], s[MAXN];
queue<int> Q;

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d %d", deg+i, s+i);
    if (deg[i] == 1) Q.push(i);
  }

  vector<pair<int, int>> ans;

  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    if (deg[x] == 0) continue;

    ans.push_back({x, s[x]});

    deg[s[x]]--;
    s[ s[x] ] ^= x;

    if (deg[s[x]] == 1) Q.push(s[x]);
  }

  printf("%d\n", (int)ans.size());
  for (auto &p: ans) printf("%d %d\n", p.first, p.second);
  return 0;
}