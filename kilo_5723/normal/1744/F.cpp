#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn], p[maxn];
ll f(ll n) { return n<0?0:n * (n + 1) / 2; }
ll solve(ll n, ll m, ll k) {
  if (k <= 0) return n * m - solve(m, n, 1 - k);
  if (m - n < k)
    return n * m - f(m - k);
  else
    return n * (k - 1) + f(n);
  // int ans = 0;
  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j < m; j++)
  //     if (j - i < k) ans++;
  // return ans;
}
ll calc(int l1, int r1, int l2, int r2, int len) {
  if (l1 < l2) return 0;
  if (r2 < r1) return 0;
  ll n = l1 - l2 + 1, m = r2 - r1 + 1;
  ll l = 1 + l2 - r1, r = len + l2 - r1;
  // printf("%lld %lld %lld %lld\n",n,m,l,r);
  // printf("%d %d %d %d %d\n",l1,r1,l2,r2,len);
  int ans = 0;
  // for (int i = 0; i < n; i++)
  //   for (int j = 0; j < m; j++)
  //     if (j - i >= l & j - i <= r) ans++;
  // return ans;
  return n * m - solve(n, m, l) - solve(m, n, -r);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      p[a[i]] = i;
    }
    ll ans = 0;
    int l = n, r = 0;
    p[n] = n;
    for (int i = 0; i < n; i++) {
      l = min(l, p[i]);
      r = max(r, p[i]);
      ans += calc(l, r + 1, 0, p[i + 1], i * 2 + 2) +
             calc(l, r + 1, p[i + 1] + 1, n, i * 2 + 2);
    }
    printf("%lld\n", ans);
  }
  return 0;
}