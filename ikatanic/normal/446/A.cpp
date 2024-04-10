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

const int MAXN = 100100;
const int inf = 2e9;

int a[MAXN];
int r[MAXN], l[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  int cur = 0, last = 0;
  REP(i, n) {
    if (a[i] <= last) cur = 0;
    l[i] = ++cur;
    last = a[i];
  }
  cur = 0, last = 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] >= last) cur = 0;
    r[i] = ++cur;
    last = a[i];
  }
  
  int ans = 0;
  REP(i, n) {
    ans = max(ans, l[i]);
    ans = max(ans, r[i]);
    
    int prev = -inf, next = inf, prevlen = 0, nextlen = 0;
    if (i > 0) prev = a[i-1], prevlen = l[i-1];
    if (i < n-1) next = a[i+1], nextlen = r[i+1];
    if (prev+1 < next) ans = max(ans, prevlen + 1 + nextlen);

    ans = max(ans, prevlen + 1);
    ans = max(ans, nextlen + 1);
  }
  
  printf("%d\n", ans);
  return 0;
}