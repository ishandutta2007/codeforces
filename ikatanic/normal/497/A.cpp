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

const int MAXN = 1010;

char a[MAXN][MAXN];
bool dead[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%s", a[i]);
  
  vector<int> v;
  REP(i, m) v.push_back(i);

  while (true) {
    bool ch = false;
    REP(i, n-1) for (int j: v)
      if (a[i][j] > a[i+1][j]) dead[j] = ch = true; else
        if (a[i][j] < a[i+1][j]) break;
    
    v.clear();
    REP(i, m)
      if (!dead[i]) v.push_back(i);
    if (!ch) break;
  }
  
  printf("%d\n", m - (int)v.size());
  return 0;
}