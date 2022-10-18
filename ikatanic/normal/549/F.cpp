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

const int MAX = 1000100;
const int off = 1<<19;
const int inf = 1e9;

int a[MAX], s[MAX], c[MAX];
pair<int, int> T[2*off];
int n, k;

pair<int, int> getmax(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return {-inf, -1};
  if (lo >= a && hi <= b) return T[i];
  return max(
    getmax(i*2, lo, (lo+hi)/2, a, b),
    getmax(i*2+1, (lo+hi)/2, hi, a, b)
  );
}

llint solve(int lo, int hi) {
  if (lo >= hi) {
    for (int i = lo; i <= hi; ++i)
      c[s[i]]--;
    return 0;
  }

  int m = getmax(1, 0, off, lo, hi).second;
  assert(m != -1);

  llint ans = 0;
  if (hi-m < m-lo) {
    for (int i = m+1; i <= hi; ++i)
      c[s[i]]--;
    
    for (int i = m+1; i <= hi; ++i)
      ans += c[(s[i] - (a[m]%k) + k) % k];
    ans--;

    ans += solve(lo, m);
    for (int i = m+1; i <= hi; ++i)
      c[s[i]]++;
    ans += solve(m+1, hi);
  } else {
    for (int i = lo; i <= m; ++i)
      c[s[i]]--;

    for (int i = lo; i <= m; ++i)
      ans += c[(s[i] + a[m]) % k];
    ans--;
    
    ans += solve(m+1, hi);
    for (int i = lo; i <= m; ++i)
      c[s[i]]++;
    ans += solve(lo, m);
  }

  return ans;
}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", a+i);
  s[0] = 0;
  REP(i, n) s[i + 1] = (s[i] + a[i]) % k;
  REP(i, n+1) c[s[i]]++;
  
  REP(i, n) T[off + i] = {a[i], i};
  for (int i = off-1; i > 0; --i)
    T[i] = max(T[i*2], T[i*2+1]);

  llint ans = solve(0, n);
  printf("%lld\n", ans);
  return 0;
}