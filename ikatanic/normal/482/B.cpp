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

const int MAXN = 1<<17;
const int MAXB = 30;

int a[MAXN][MAXB];
int l[MAXN], r[MAXN], q[MAXN];

int T[2*MAXN];
int offset = 1<<17;

int query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return (1<<MAXB)-1;
  if (lo >= a && hi <= b) return T[i];
  return query(i*2, lo, (lo+hi)/2, a, b) & query(i*2+1, (lo+hi)/2, hi, a, b);
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    scanf("%d %d %d", l+i, r+i, q+i); --l[i], --r[i];
    REP(j, MAXB)
      if (q[i]&(1<<j)) a[l[i]][j]++, a[r[i]+1][j]--;
  }
  
  int cur[MAXB];
  REP(i, MAXB) cur[i] = 0;
  REP(i, n) {
    int x = 0;
    REP(j, MAXB) {
      cur[j] += a[i][j];
      if (cur[j]) x |= 1<<j;
    }
    T[offset+i] = x;
  }
  
  for (int i = offset-1; i > 0; --i)
    T[i] = T[i*2] & T[i*2+1];
  
  REP(i, m)
    if (query(1, 0, offset, l[i], r[i]+1) != q[i]) {
      puts("NO");
      return 0;
    }

  puts("YES");
  REP(i, n) printf("%d ", T[offset+i]);
  printf("\n");
  return 0;
}