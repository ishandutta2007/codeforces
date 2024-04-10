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

const int MAX = 4040;

llint v[MAX], p[MAX], d[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%lld %lld %lld", &v[i], &d[i], &p[i]);

  vector<int> a;
  REP(i, n) a.push_back(i);

  vector<int> ans;
  while (!a.empty()) {
    REP(j, (int)a.size())
      if (p[a[j]] < 0) { 
        FOR(k, j + 1, (int)a.size())
          p[a[k]] -= d[a[j]];
        a.erase(a.begin() + j);
        --j;
      }
    
    if (a.empty()) break;

    int i = a[0];
    a.erase(a.begin());
    ans.push_back(i);
    for (int j = 0; j < (int)a.size() && j < v[i]; ++j)
      p[a[j]] -= v[i] - j;
  }

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x+1);
  printf("\n");
  return 0;
}