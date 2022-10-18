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

const int MAX = 59;
const int inf = 1e9;

int f[110][1<<16];
int l[110][1<<16];
int r[110][1<<16];
int s[MAX];
int a[110];

inline void update(int i, int j, int d, int k, int last) {
  if (d < f[i][j]) f[i][j] = d, l[i][j] = last, r[i][j] = k;
}

int main(void) {
  vector<int> v;
  FOR(i, 2, MAX) {
    bool prime = true;
    for (int j = 2; j*j <= i; ++j)
      if (i%j == 0) { prime = false; break; }
    if (prime) v.push_back(i);
  
    s[i] = 0;
    REP(j, (int)v.size())
      if (i%v[j] == 0) s[i] |= 1<<j;
  }

  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  
  REP(i, n+1) REP(j, 1<<16) f[i][j] = inf;

  f[0][0] = 0;
  REP(i, n) REP(j, 1<<16)
    if (f[i][j] < inf)
      FOR(k, 1, MAX)
        if ((j&s[k]) == 0)
          update(i+1, j|s[k], f[i][j] + abs(k - a[i]), k, j);
  
  int best = 0;
  REP(j, 1<<16)
    if (f[n][j] < f[n][best]) best = j;
  
  vector<int> ans;
  for (int i = n; i > 0; --i) {
    ans.push_back(r[i][best]);
    best = l[i][best];
  }

  reverse(ans.begin(), ans.end());
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}