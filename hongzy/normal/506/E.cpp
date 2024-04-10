// LUOGU_RID: 90393476
#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 205;
const int M = 320;
const int mod = 10007;
void upd(int &x, int y) {
  (x += y) >= mod ? x -= mod : 0;
}
int cn;
struct mat {
  int a[M][M];
  mat operator * (const mat &b) {
    mat ans;
    rep(i, 1, cn) {
      rep(j, i, cn) {
        ll t = 0;
        rep(k, i, j) t += a[i][k] * b.a[k][j];
        ans.a[i][j] = t >= mod ? t % mod : t;
      }
    }
    return ans;
  }
  void e() { rep(i, 1, cn) rep(j, 1, cn) a[i][j] = i == j; }
  void u() { rep(i, 1, cn) rep(j, 1, cn) a[i][j] = 0; }
};
char s[N];
int n, m, len, g[N][N][N];
mat mpow(mat a, int w) {
  mat z; z.e();
  for(; w; w >>= 1, a = a * a)
    if(w & 1) z = z * a;
  return z;
}
int c[N]; //c[red]
int solve(bool ty) { //ty = 1: T -> T
  // S, 1, 2, ..., n (n+1)
  // 1, 2, ..., m, T (m+1)
  cn = n + m + 2;
  mat tr; tr.u();
  rep(i, 1, n) tr.a[i][i + 1] = 1;
  rep(i, 2, n + 1) tr.a[i][i] = 24;
  rep(i, 1, m) tr.a[n + 1 + i][n + 1 + i + 1] = 1;
  rep(i, 1, m) tr.a[n + 1 + i][n + 1 + i] = 25;
  if(ty) tr.a[cn][cn] = 26;
  rep(i, 0, n) if(c[i]) upd(tr.a[1 + i][cn - ((n - i + 1) >> 1)], c[i]);
  return mpow(tr, (n + len + 1) / 2 + 1).a[1][cn];
}
int main() {
  scanf("%s%d", s + 1, &len);
  n = strlen(s + 1);
  g[0][1][n] = 1;
  rep(i, 0, n) rep(l, 1, n) per(r, n, l) if(g[i][l][r]) {
    if(s[l] == s[r]) {
      upd(g[i][l + 1][r - 1], g[i][l][r]);
    } else {
      upd(g[i + 1][l + 1][r], g[i][l][r]);
      upd(g[i + 1][l][r - 1], g[i][l][r]);
    }
  }
  rep(i, 0, n) {
    rep(l, 1, n) {
      upd(c[i], g[i][l][l]);
      if(s[l] == s[l + 1]) upd(c[i], g[i][l][l + 1]);
    }
  }
  m = (n + 1) >> 1;
  int res = solve(1);
  if((n + len) & 1) {
    rep(i, 0, n) {
      c[i] = 0;
      rep(l, 1, n - 1) if(s[l] == s[l + 1]) upd(c[i], g[i][l][l + 1]);
    }
    upd(res, mod - solve(0));
  }
  printf("%d\n", res);
  return 0;
}