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

const int MAXN = 101000;
const int K = 320;
const int MK = 1000;

int x[MAXN];
llint f[MAXN];

int a[MK][MK];
int lo[MK], hi[MK];

int first[MK], last[MK];
llint diff[MK];
llint sum[MK];
llint suma[MK][MK];

llint query_whole(int j) {
  return sum[j];
}

llint query_some(int j, int l, int r) {
  llint ans = 0;
  FOR(i, lo[j], hi[j])
    if (l <= i && i < r) {
      ans += f[i];
      if (first[j]) ans += diff[j] + abs(x[i] - first[j]);
    }
  return ans;
}

void update_whole(int j, int x) {
  if (first[j]) {
    diff[j] += abs(x - last[j]);
    sum[j] += abs(x - last[j])*llint(hi[j] - lo[j]);
    last[j] = x;
    return;
  }

  int low = 0, high = hi[j]-lo[j];
  while (low < high) {
    int mid = (low + high)/2;
    if (a[j][mid] <= x) low = mid+1; else
      high = mid;
  }

  first[j] = last[j] = x, diff[j] = 0;

  sum[j] += llint(low)*x - suma[j][low];
  sum[j] += suma[j][hi[j]-lo[j]]-suma[j][low] - llint(hi[j]-lo[j] - low)*x;
}

void update_some(int j, int l, int r, int v) {
  if (first[j]) {
    sum[j] = 0;
    suma[j][0] = 0;
    FOR(i, lo[j], hi[j]) {
      f[i] += diff[j] + abs(x[i] - first[j]);
      x[i] = last[j];
      sum[j] += f[i];
      a[j][i-lo[j]] = last[j];
      suma[j][i-lo[j]+1] = suma[j][i-lo[j]] + last[j];
    }
    first[j] = last[j] = diff[j] = 0;
  }

  FOR(i, lo[j], hi[j]) {
    if (l <= i && i < r) {
      f[i] += abs(v - x[i]);
      sum[j] += abs(v - x[i]);
      x[i] = v;
    }
    a[j][i-lo[j]] = x[i];
  }

  int m = hi[j] - lo[j];
  sort(a[j], a[j] + m);
  suma[j][0] = 0;
  REP(i, m)
    suma[j][i+1] = suma[j][i] + a[j][i];
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) x[i] = i+1, f[i] = 0;
  
  int g = (n + K-1) / K;
  REP(i, g) {
    lo[i] = K*i;
    hi[i] = min(K*(i+1), n);
    suma[i][0] = 0;
    FOR(j, lo[i], hi[i]) {
      a[i][j-lo[i]] = x[j];
      suma[i][j-lo[i]+1] = suma[i][j-lo[i]] + x[j];
    }
    sum[i] = diff[i] = first[i] = last[i] = 0;
  }
  
  REP(i, m) {
    int type, l, r, x;
    scanf("%d", &type);
    

    if (type == 1) {
      scanf("%d %d %d", &l, &r, &x); --l;
    } else {
      scanf("%d %d", &l, &r); --l;
    }
    
    llint ans = 0;
    REP(j, g) {
      if (hi[j] <= l || r <= lo[j]) continue;
      if (l <= lo[j] && hi[j] <= r) {
        if (type == 1) update_whole(j, x); else
          ans += query_whole(j);
      } else {
        if (type == 1) update_some(j, l, r, x); else
          ans += query_some(j, l, r);
      }
    }

    if (type == 2) printf("%I64d\n", ans);
  }
      
  return 0;
}