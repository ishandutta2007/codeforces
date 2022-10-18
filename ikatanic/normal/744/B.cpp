#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int inf = 1e9;

vector<int> ask(int n, vector<int> v) {
  printf("%d\n", (int)v.size());
  for (int x: v) printf("%d ", x+1);
  printf("\n");
  fflush(stdout);
  
  vector<int> ret(n);
  REP(j, n) scanf("%d", &ret[j]);
  return ret;
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  int N = 1024;
  vector<pair<int, int>> q[20];
  q[0].push_back({0, N/2});
  q[1].push_back({N/2, N});

  for (int i = 2; i < 20; i += 2) {
    for (int j = i-2; j < i; ++j) {
      for (auto& p: q[j]) {
        q[i].push_back({p.first, (p.first + p.second) / 2});
        q[i+1].push_back({(p.first + p.second) / 2, p.second});
      }
    }
  }

  vector<int> ans[20];
  REP(i, 20) {
    vector<int> v;
    for (auto& p: q[i])
      for (int j = p.first; j < p.second && j < n; ++j)
        v.push_back(j);

    if (v.size() == 0) {
      ans[i] = vector<int>(n, inf);
      continue;
    }

    ans[i] = ask(n, v);
  }

  printf("-1\n");
  REP(i, n) {
    int m = inf;
    REP(j, 20) {
      bool ok = true;
      for (auto& p: q[j])
        if (p.first <= i && i < p.second) { ok = false; break; }
      if (ok) m = min(m, ans[j][i]);
    }
    printf("%d\n", m);
  }
  fflush(stdout);
  return 0;
}