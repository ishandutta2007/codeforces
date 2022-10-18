#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;
const int M = 3e7;

int a[MAX];
short cnt[M];
int val[M];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  
  set<int> S(a, a + n);
  int P = M+1;
  auto f = [&] (llint x) {
    return ((x%P) + P)%P;
  };

  while (true) {
    P--;
    set<int> B;
    for (int x: S) {
      B.insert(f(x));    
    }
    if (B.size() == S.size()) break;
  }

  REP(i, n) {
    val[f(a[i])] = a[i];
    cnt[f(a[i])]++;
  }

  int ans = 0;
  REP(i, n) ans += a[i] == 0;
  
  REP(i, n) REP(j, n) {
    if (a[i] == 0 && a[j] == 0) continue;
    if (i == j) continue;

    static llint tmp[MAX];
    int m = 0;
    tmp[m++] = a[i];
    tmp[m++] = a[j];
    cnt[f(a[i])]--, cnt[f(a[j])]--;
    
    while (true) {
      tmp[m] = tmp[m-1] + tmp[m-2];
      llint x = f(tmp[m]);
      if (val[x] != tmp[m]) break;
      if (cnt[x] == 0) break;
      cnt[x]--;
      m++;
    }
    
    ans = max(ans, m);
    REP(i, m) cnt[f(tmp[i])]++;
  }    
  printf("%d\n", ans);
  return 0;
}