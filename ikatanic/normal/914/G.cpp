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

const int K = 17;
const int M = 1 << 17;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

void fastAnd(int *A, int *B, int *C, int n) {
  if (n == 0) { C[0] = mul(A[0], B[0]); return; }
  int mid = 1<<(n-1);
  fastAnd(A+mid, B+mid, C+mid, n-1);
  REP(i, mid) A[i] = add(A[i], A[mid+i]), B[i] = add(B[i], B[mid+i]);
  fastAnd(A, B, C, n-1);
  REP(i, mid) A[i] = sub(A[i], A[mid+i]), B[i] = sub(B[i], B[mid+i]), C[i] = sub(C[i], C[mid+i]);
}


int inv2 = (mod + 1) / 2;

struct data {
  int x[1<<K];
} A[K+1], B[K+1], C[K+1];

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

void fast_xor(data &a, data &b, data &c) {
  A[K] = a, B[K] = b;
  mult(K);
  c = C[K];
}


int F[M];

int s[M];
int c[M];

int ab[M];
int de[M];

int tmp1[M], tmp2[M];

data d, e, d_xor_e;

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    s[x]++;
  }

  F[0] = 0;
  F[1] = 1;
  FOR(i, 2, M) {
    F[i] = add(F[i - 1], F[i - 2]);
  }

  REP(x, M) {
    int invx = x ^ (M - 1);
    for (int y = invx; y >= 0; y = (y - 1) & invx) {
      ab[x | y] = add(ab[x | y], mul(s[x], s[y]));
      if (y == 0) break;
    }
  }

  REP(x, M) ab[x] = mul(ab[x], F[x]);

  REP(x, M) c[x] = mul(s[x], F[x]);

  REP(x, M) d.x[x] = e.x[x] = s[x];

  fast_xor(d, e, d_xor_e);

  REP(x, M) de[x] = mul(d_xor_e.x[x], F[x]);

  REP(x, M) tmp1[x] = 0;
  fastAnd(ab, c, tmp1, K);
  fastAnd(tmp1, de, tmp2, K);


  int ret = 0;
  REP(i, K) ret = add(ret, tmp2[1 << i]);

  printf("%d\n", ret);
  return 0;
}