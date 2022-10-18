#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 500100;
const llint inf = 1e18;

vector<int> E[MAXN];
int u[MAXN], v[MAXN], x[MAXN];
llint d[MAXN];
bool can[MAXN];

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, m+k) {
    if (i < m) scanf("%d", u+i); else
      u[i] = 1;
    scanf("%d %d", v+i, x+i); --u[i], --v[i];
    E[u[i]].push_back(i);
    E[v[i]].push_back(i);
  }
  
  auto cmp = [] (const int &a, const int &b) {
    if (d[a] != d[b]) return d[a] < d[b];
    if (can[a] != can[b]) return can[a] < can[b];
    return a < b;
  };

  static set<int, decltype(cmp)> S(cmp);
  REP(i, n) d[i] = inf;
  d[0] = 0;
  S.insert(0);
  
  int cnt = 0;
  while (S.size()) {
    int a = *S.begin();
    S.erase(S.begin());
    
    if (can[a]) cnt++;

    for (int i: E[a]) {
      int b = u[i] == a ? v[i] : u[i];
      llint nd = d[a] + x[i];
      if (nd < d[b] || (nd == d[b] && i < m && can[b])) {
        S.erase(b);
        d[b] = nd;
        can[b] = i >= m;
        S.insert(b);
      }
    }
  }

  int ans = k - cnt;
  printf("%d\n", ans);
  return 0;
}