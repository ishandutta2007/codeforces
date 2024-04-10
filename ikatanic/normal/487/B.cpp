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

const int MAXN = 100010;
const int inf = 2e9;

int a[MAXN];
int f[MAXN];

multiset<int> S, F;

int get_diff() {
  if (S.size() == 0) return inf;
  return *(--S.end()) - *S.begin();
}

int main(void) {
  int n, s, l;
  scanf("%d %d %d", &n, &s, &l);
  REP(i, n) scanf("%d", a+i);
  
  if (l > n) { puts("-1"); return 0; }

  REP(i, l) S.insert(a[i]);
  REP(i, l) f[i] = inf;

  f[0] = 0;
  F.insert(0);
  F.insert(inf);

  int lo = 0;
  FOR(i, l, n+1) {
    int hi = i-l;
    // sad sam na i-1vom
    while (lo <= hi && get_diff() > s) {
      S.erase(S.find(a[lo]));
      F.erase(F.find(f[lo]));
      lo++;
    }

    f[i] = *(F.begin()) + 1;
    F.insert(f[hi+1]);
    S.insert(a[i]);
  }

  if (f[n] < inf) printf("%d\n", f[n]); else
    puts("-1");
    
  return 0;
}