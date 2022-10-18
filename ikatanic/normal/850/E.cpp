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

const int M = (1<<20) + 1;

const int P = 20;
const int mod = 1e9 + 7;

int inv2 = (mod + 1) / 2;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

struct data {
  int x[1<<P];
} A[P+1], B[P+1], C[P+1];

void mult(int n) {
  if (n == 0) {
    C[n].x[0] = mul(A[n].x[0], B[n].x[0]);
    return;
  }
    
  int m = (1<<n) / 2;
  REP(i, m) {
    A[n-1].x[i] = add(A[n].x[i], A[n].x[m + i]);
    B[n-1].x[i] = add(B[n].x[i], B[n].x[m + i]);
  }
    
  mult(n-1);
  REP(i, m) C[n].x[i] = C[n-1].x[i];
    
  REP(i, m) {
    A[n-1].x[i] = sub(A[n].x[i], A[n].x[m + i]);
    B[n-1].x[i] = sub(B[n].x[i], B[n].x[m + i]);
  }
    
  mult(n-1);
    
  REP(i, m) {
    int sum = add(C[n].x[i], C[n-1].x[i]);
    int diff = sub(C[n].x[i], C[n-1].x[i]);
    C[n].x[i] = mul(sum, inv2);
    C[n].x[m + i] = mul(diff, inv2);
  }
}

void mult(data &a, data &b, data &c) {
  A[P] = a, B[P] = b;
  mult(P);
  c = C[P];
}

char f[M];

data da, db, dc;

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", f);

  REP(i, 1<<n) {
    if (f[i] == '1') da.x[i] = db.x[i] = 1;
  }
    
  mult(da, db, dc);

  int ret = 0;
  REP(s, 1<<n) {
    int cnt = 0;
    REP(i, n) {
      if (!(s & (1<<i))) cnt++;
    }
    ret = add(ret, mul(dc.x[s], 1<<cnt));
  }
  
  ret = mul(ret, 3);
  printf("%d\n", ret);
  return 0;
}