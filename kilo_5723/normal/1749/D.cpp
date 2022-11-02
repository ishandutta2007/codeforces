#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 3e5 + 5;
bool isprime[maxn];
ll sgl[maxn], powm[maxn], spow[maxn];
ll imv[maxn];
ll m;
int main() {
  int n;
  scanf("%d%lld", &n, &m);
  memset(isprime, true, sizeof(isprime));
  for (int i = 2; i <= n; i++)
    if (isprime[i]) {
      for (int j = i * 2; j <= n; j += i) isprime[j] = false;
    }
  ll k = m;
  for (int i = 2; i <= n; i++) {
    if (isprime[i]) k /= i;
    imv[i] = k % mod;
    // printf("%d %lld\n",i,imv[i]);
  }
  sgl[1] = m%mod;
  for (int i = 2; i <= n; i++) sgl[i] = imv[i] % mod * sgl[i - 1] % mod;
  powm[0] = 1;
  for (int i = 1; i <= n; i++) powm[i] = m % mod * powm[i - 1] % mod;
  spow[0] = 1;
  for (int i = 1; i <= n; i++) spow[i] = (powm[i] + spow[i - 1]) % mod;
  ll ans = 0;
  for (int i = 2; i <= n; i++)
    ans = ans + (m % mod - imv[i]) % mod * sgl[i - 1] % mod * spow[n - i] % mod;
  printf("%lld\n", (ans % mod + mod) % mod);
  // }
  return 0;
}