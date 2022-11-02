#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 5;
ll mod;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll n) { return qpow(n, mod - 2); }
vector<int> e[maxn];
ll dp[maxn][maxn];
ll cnt[maxn][maxn], sum[maxn][maxn], lef[maxn][maxn], rig[maxn][maxn];
void dfs(int u, int f) {
  int m = 0;
  for (auto v : e[u])
    if (v != f) dfs(v, u);
  for (auto v : e[u])
    if (v != f) memcpy(cnt[++m], dp[v], sizeof(dp[v]));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j < maxn; j++)
      sum[i][j] = (sum[i][j - 1] + cnt[i][j]) % mod;
  fill(lef[0], lef[1], 1);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < maxn; j++) lef[i][j] = lef[i - 1][j] * sum[i][j] % mod;
  fill(rig[m + 1], rig[m + 2], 1);
  for (int i = m; i >= 1; i--)
    for (int j = 0; j < maxn; j++) rig[i][j] = rig[i + 1][j] * sum[i][j] % mod;
  for (int i = 1; i < maxn; i++) dp[u][i] = lef[m][i];
  if (u != 1)
    for (int i = 1; i <= m; i++) {
      ll tmp = 0;
      for (int j = 1; j < maxn; j++) {
        dp[u][j] = (dp[u][j] + cnt[i][j] * tmp) % mod;
        tmp = (tmp + lef[i - 1][j] * rig[i + 1][j]) % mod;
      }
    }
}
ll fact[maxn], ifac[maxn];
ll comb(int i, int j) { return fact[i] * ifac[j] % mod * ifac[i - j] % mod; }
ll tmp[maxn];
int main() {
  int n;
  scanf("%d%lld", &n, &mod);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
  ifac[maxn - 1] = inv(fact[maxn - 1]);
  for (int i = maxn - 1; i; i--) ifac[i - 1] = ifac[i] * i % mod;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 1);
  for (int i = 1; i < maxn; i++) {
    tmp[i] = dp[1][i];
    for (int j = 0; j < i; j++) tmp[i] = (tmp[i] - tmp[j] * comb(i, j)) % mod;
  }
  for (int i = 1; i < n; i++) printf("%lld ", (tmp[i] + mod) % mod);
  puts("");
  return 0;
}