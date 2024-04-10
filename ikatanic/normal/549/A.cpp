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

char a[55][55];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  
  int ans = 0;
  REP(i, n-1) REP(j, m-1) {
    vector<char> v;
    REP(x, 2) REP(y, 2) v.push_back(a[i+x][j+y]);
    sort(v.begin(), v.end());
    ans += v == vector<char>({'a', 'c', 'e', 'f'});
  }

  printf("%d\n", ans);
  return 0;
}