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

const int MAXN = 200200;

int a[MAXN];
llint s[MAXN];
int n;

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);

  s[0] = 0;
  REP(i, n) s[i+1] = s[i] + a[i];

  auto calc = [&] (int i, int k, int e) {
    llint sum = a[i] + s[i] - s[i-k] + s[n] - s[n-k];
    if (e) return (sum + a[i+1]) / (2.0*k + 2) - (a[i] + a[i+1])/2.0;
    return sum / (2.0*k+1) - a[i];
  };

  double best = 0;
  int p = 0;
  int k = 0;
  bool even = false;


  REP(i, n) {
    REP(e, 2) {
      int m = min(i, n-i-1-e);
      if (m > 0) {
        int lo = 0, hi = m;
        while (lo < hi) {
          int mid = (lo + hi) / 2;
          if (calc(i, mid, e) <= calc(i, mid + 1, e)) lo = mid + 1; else
            hi = mid;
        }
        if (calc(i, lo, e) > best) {
          best = calc(i, lo, e);
          p = i;
          k = lo;
          even = e;
        }
      }
    }
  }

  vector<int> ans;
  ans.push_back(a[p]);
  if (even) ans.push_back(a[p+1]);
  REP(i, k) ans.push_back(a[p-i-1]), ans.push_back(a[n-i-1]);

  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}