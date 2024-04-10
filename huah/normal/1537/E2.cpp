#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 5e5 + 5, mod1 = 1e9 + 7, mod2 = 998244353;
const int b1 = 233, b2 = 3939;
ll hs1[N], hs2[N], f1[N], f2[N];
int n, k;
char s[N], ans[N];
void iniths(ll* hs, int b, int mod) {
  for (int i = 1; i <= n; i++) hs[i] = (hs[i - 1] * b + s[i] - 'a' + 1) % mod;
}
vector<ll> vc1[N], vc2[N];
char getchar(int x, int len) {
  if (len % x == 0) return s[x];
  return s[len % x];
}
ll geths(int x, int len, vector<ll>& vc, ll* f, int mod, ll* hs) {
  ll curhs = vc[len / x];
  if (len % x == 0) return curhs;
  return (curhs * f[len % x] % mod + hs[len % x]) % mod;
}
bool cmp(int x, int y) {
  int l = 0, r = k, ans;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (geths(x, m, vc1[x], f1, mod1, hs1) ==
            geths(y, m, vc1[y], f1, mod1, hs1) &&
        geths(x, m, vc2[x], f2, mod2, hs2) ==
            geths(y, m, vc2[y], f2, mod2, hs2))
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  if (ans == k) return true;
  return getchar(x, ans + 1) < getchar(y, ans + 1);
}
int main() {
  f1[0] = f2[0] = 1;
  for (int i = 1; i < N; i++)
    f1[i] = f1[i - 1] * b1 % mod1, f2[i] = f2[i - 1] * b2 % mod2;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  iniths(hs1, b1, mod1);
  iniths(hs2, b2, mod2);
  for (int i = 1; i <= n; i++) {
    ll h1 = 0, h2 = 0;
    for (int j = 0; j <= k; j += i) {
      vc1[i].push_back(h1);
      vc2[i].push_back(h2);
      h1 = (h1 * f1[i] % mod1 + hs1[i]) % mod1;
      h2 = (h2 * f2[i] % mod2 + hs2[i]) % mod2;
    }
  }
  int curans = 1;
  for (int i = 2; i <= n; i++)
    if (cmp(i, curans)) curans = i;
  for (int i = 1; i <= curans; i++)
    for (int j = i; j <= k; j += curans) ans[j] = s[i];
  for (int i = 1; i <= k; i++) putchar(ans[i]);
  putchar('\n');
}