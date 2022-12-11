#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 32;
const int mod = 1e9 + 7;
int k, buf[128], ans[N];
ll n;
struct mat {
  int a[N][N];
  mat operator * (const mat &b) const {
    mat ans;
    rep(i, 0, k) rep(j, 0, k) {
      ans.a[i][j] = 0;
      rep(w, 0, k)
        ans.a[i][j] = (ans.a[i][j] + (ll)a[i][w] * b.a[w][j]) % mod;
    }
    return ans;
  }
} q[128][N], L[N], R[N];
void Mul(const mat &b) {
  static int res[N];
  rep(i, 0, k) {
    res[i] = 0;
    rep(j, 0, k)
      res[i] = (res[i] + (ll)ans[j] * b.a[j][i]) % mod;
  }
  copy(res, res + k + 1, ans);
}
int main() {
  scanf("%lld%d", &n, &k);
  int w = 0;
  for(ll x = n; x; x /= k) buf[w++] = x % k;
  rep(i, 0, k - 1)
    rep(x, 0, k) rep(y, 0, k)
      q[0][i].a[x][y] = x == y || y == i;
  rep(i, 1, w - 1) {
    L[0] = q[i - 1][0];
    rep(x, 1, k - 1) L[x] = L[x - 1] * q[i - 1][x];
    R[k - 1] = q[i - 1][k - 1];
    per(x, k - 2, 0) R[x] = q[i - 1][x] * R[x + 1];
    rep(x, 0, k - 1)
      q[i][x] = x ? R[x] * L[x - 1] : R[0];
  }
  ans[k] = 1;
  int s = 0;
  per(i, w - 1, 0) {
    while(buf[i] --) {
      Mul(q[i][s]);
      s = s == k - 1 ? 0 : s + 1;
    }
  }
  rep(i, 1, k) (*ans += ans[i]) %= mod;
  printf("%d\n", *ans);
  return 0;
}