#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using db = double;
const int N = 64, m = 50;
int n, p0;
db p, a[N][N], b[N][N], A[N][N], B[N][N], f[N][N];
struct mat {
  db a[N][N];
  mat operator * (const mat &b) const {
    mat ans;
    rep(i, 1, m + 1) rep(j, 1, m + 1) {
      ans.a[i][j] = 0;
      rep(k, 1, m + 1)
        ans.a[i][j] += a[i][k] * b.a[k][j];
    }
    return ans;
  }
} fir, tr;
mat Pow(mat a, int w) {
  mat ans = a; -- w;
  for(; w >= 1; w >>= 1, a = a * a)
    if(w & 1) ans = ans * a;
  return ans;
}
int main() {
  scanf("%d%d", &n, &p0);
  p = p0 / 1e9;
  a[1][1] = p; a[1][2] = b[1][2] = 1 - p;
  rep(i, 2, m + 1) {
    a[i][1] = p;
    a[i][2] = 1 - p + p * p;
    b[i][2] = 1 - p;
    rep(j, 3, i + 1) {
      a[i][j] = a[i][j - 1] * a[i - 1][j - 1];
      b[i][j] = b[i][j - 1] * a[i - 1][j - 1];
    }
  }
  rep(i, 1, m + 1) {
    rep(j, 1, i + 1) {
      A[i][j] = a[i][j] * (1 - a[i - 1][j]);
      B[i][j] = b[i][j] * (1 - a[i - 1][j]);
    }
  }
  f[1][1] = 1; f[1][2] = 2;
  db s = 0;
  rep(i, 2, m) {
    rep(j, 2, m) {
      f[i][j] = j;
      s = 0;
      rep(k, 1, j - 1) s += A[i - 1][k];
      rep(k, 1, j - 1)
        f[i][j] += f[i - 1][k] * A[i - 1][k] / s;
    }
    f[i][1] = 1;
    s = 0;
    rep(k, 2, m) s += B[i - 1][k];
    rep(k, 2, m)
      f[i][1] += f[i - 1][k] * B[i - 1][k] / s;
  }
  if(n <= m) {
    // cerr << "!\n";
    db res = 0;
    rep(i, 1, m) res += A[n][i] * f[n][i];
    printf("%.15f\n", res);
    return 0;
  }
  rep(i, 1, m + 1) fir.a[1][i] = i == m + 1 ? 1 : f[m][i];
  rep(j, 1, m) tr.a[m + 1][j] = j;
  tr.a[m + 1][m + 1] = 1;
  rep(j, 2, m) {
    s = 0;
    rep(k, 1, j - 1) s += A[m][k];
    rep(k, 1, j - 1)
      tr.a[k][j] += A[m][k] / s;
  }
  s = 0;
  rep(k, 2, m) s += B[m][k];
  rep(k, 2, m)
    tr.a[k][1] += B[m][k] / s;
  fir = fir * Pow(tr, n - m);
  db res = 0;
  rep(i, 1, m) res += A[m + 1][i] * fir.a[1][i];
  printf("%.15f\n", res);
  return 0;
}