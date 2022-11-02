#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 100;
ll c[maxn][maxn];
ll a[maxn][3];
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
const ll inv2 = qpow(2, mod - 2);
int main() {
  for (int i = 0; i < maxn; i++) c[i][0] = c[i][i] = 1;
  for (int i = 1; i < maxn; i++)
    for (int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
  a[2][0] = 1;
  a[2][1] = 0;
  a[2][2] = 1;
  for (int i = 4; i < maxn; i += 2) {
    a[i][0] = (c[i][i / 2] * inv2 % mod + a[i - 2][1]) % mod;
    a[i][1] = (c[i - 2][i / 2] % mod + a[i - 2][0]) % mod;
    ;
    a[i][2] = 1;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    printf("%lld %lld %lld\n", a[n][0], a[n][1], a[n][2]);
  }
  return 0;
}