#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;
#define x first
#define y second

const int MAXN = 500100;

bool color[MAXN], used[MAXN];
int l[MAXN], r[MAXN];
vector<par> E[MAXN];

void dfs(int x) {
  for (par p: E[x])
    if (!used[p.y]) {
      color[p.y] = (x < p.x);
      used[p.y] = true;
      dfs(p.x);
    }
}

int main(void) {
  int n;
  scanf("%d", &n);
  vector<int> x;
  REP(i, n) {
    scanf("%d %d", l+i, r+i);
    l[i] = 2*l[i] - 1;
    r[i] = 2*r[i];
    x.push_back(l[i]);
    x.push_back(r[i]);
  }
    
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  REP(i, n) {
    l[i] = (lower_bound(x.begin(), x.end(), l[i]) - x.begin());
    r[i] = (lower_bound(x.begin(), x.end(), r[i]) - x.begin());
    E[l[i]].push_back({r[i], i});
    E[r[i]].push_back({l[i], i});
  }

  int m = x.size(), cnt = n;
  int last_odd = -1;
  REP(i, m)
    if (E[i].size()%2 == 1) {
      if (last_odd == -1) last_odd = i; else {
        E[last_odd].push_back({i, cnt++});
        E[i].push_back({last_odd, cnt++});
        last_odd = -1;
      }
    }

  REP(i, m) dfs(i);
  
  REP(i, n)
    printf("%d%c", color[i], i+1 < n ? ' ' : '\n');
  return 0;
}