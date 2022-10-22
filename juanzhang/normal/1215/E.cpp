#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

typedef long long ll;
const int maxn = 4e5 + 10;
int n, a[maxn], sum[maxn][20];
ll val[20][20], pos[maxn], f[1 << 20];

inline void chkmin(ll &x, ll y) {
  if (x > y) x = y;
}

int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d", a + i), a[i]--;
    pos[a[i]] += i;
    rep(j, 0, 19) {
      sum[i][j] = sum[i - 1][j] + (a[i] == j);
      val[a[i]][j] += sum[i][j];
    }
  }
  int all = (1 << 20) - 1;
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  rep(S, 0, all) {
    ll s[20];
    int cnt = 0;
    memset(s, 0, sizeof s);
    rep(i, 0, 19) {
      if (S >> i & 1) {
        cnt += sum[n][i];
        rep(j, 0, 19) {
          s[j] += val[i][j];
        }
      }
    }
    rep(i, 0, 19) {
      if (~S >> i & 1) {
        int l = cnt + 1, r = cnt + sum[n][i];
        chkmin(f[S | 1 << i], f[S] + s[i] + pos[i] - 1ll * (l + r) * (r - l + 1) / 2);
      }
    }
  }
  printf("%I64d", f[all]);
  return 0;
}