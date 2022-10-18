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

const int MAXN = 200100;

int f[MAXN], r[MAXN];
int a[MAXN];
int b[MAXN], sb[MAXN];
int vl[MAXN], vr[MAXN];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);
  REP(i, m) scanf("%d", b+i);

  sort(a, a + n);
  sort(b, b + m);

  REP(i, n)
    if (i > 0 && a[i] == a[i-1]+1) vl[i] = vl[i-1]+1; else
      vl[i] = 0;
  for (int i = n-1; i >= 0; --i)
    if (i+1 < n && a[i] == a[i+1]-1) vr[i] = vr[i+1]+1; else
      vr[i] = 0;
  
  REP(j, m) sb[b[j]]++;
  REP(i, MAXN-1) sb[i+1] += sb[i];
  
  REP(i, n) {
    f[i+1] = max(f[i+1], f[i]);
    r[i] = f[i];
    REP(j, m) {
      if (b[j] > a[i]) break;
      int last = i - (a[i] - b[j]);
      if (last >= 0) last -= vl[last];
      if (last >= 0) r[i] = max(r[i], f[last] + sb[a[i]]-sb[b[j]-1]);
    }

    REP(j, m) {
      if (b[j] < a[i]) continue;
      int last = i + b[j]-a[i];
      if (last < n) last += vr[last];
      last++;
      if (last <= n) f[last] = max(f[last], r[i] + sb[b[j]]-sb[a[i]]);
    }
    f[i+vr[i]+1] = max(f[i+vr[i]+1], r[i]);
  }

  printf("%d\n", f[n]);
  return 0;
}