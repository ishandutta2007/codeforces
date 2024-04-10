#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1e9 + 7, mod = 1e9 + 6;
ll n;

#define rep(i) for (int i = 0; i < 5; i++)

struct matrix {
  int array[5][5];

  inline void clr() {
    memset(array, 0, sizeof array);
  }

  inline int* operator [] (int pos) {
    return array[pos];
  }
} E, A, M;

inline matrix operator * (matrix a, matrix b) {
  static matrix s;
  s.clr();
  rep(i) rep(j) rep(k) s[i][j] = (s[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
  return s;
}

inline qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

inline matrix qp(matrix a, ll k) {
  matrix res = E;
  for (; k; k >>= 1, a = a * a) {
    if (k & 1) res = res * a;
  }
  return res;
}

inline int calc(int x) {
  A.clr(), A[0][x] = 1;
  return (A * qp(M, n - 3))[0][0];
}

int main() {
  int c, f1, f2, f3;
  scanf("%I64d %d %d %d %d", &n, &f1, &f2, &f3, &c);
  rep(i) E[i][i] = 1;
  M[0][0] = M[0][1] = M[1][0] = M[2][0] = M[1][2] = 1;
  int c1 = calc(2);
  int c2 = calc(1);
  int c3 = calc(0);
  A.clr(), A[0][3] = 8, A[0][4] = 1;
  M[4][3] = 2, M[4][0] = -6, M[3][0] = M[3][3] = M[4][4] = 1;
  int cnt = (A * qp(M, n - 3))[0][0];
  int ans = 1ll * qp(f1, c1) * qp(f2, c2) % P * qp(f3, c3) % P * qp(c, cnt) % P;
  printf("%d", ans);
  return 0;
}