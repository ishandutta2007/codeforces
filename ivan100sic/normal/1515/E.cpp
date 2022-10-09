// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int mod;
int n;
int dp[405][405];
int f[405], p2[405], finv[405];

int pw(int x, int y) {
  if (y == 0) return 1;
  int z = pw(x, y >> 1);
  z = z * 1ll * z % mod;
  if (y & 1) {
    z = z * 1ll * x % mod;
  }
  return z;
}

int inv(int x) {
  return pw(x, mod-2);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> mod;

  f[0] = 1;
  finv[0] = 1;
  p2[0] = 1;
  for (int i=1; i<=n; i++) {
    f[i] = f[i-1] * 1ll * i % mod;
    finv[i] = inv(f[i]);
    p2[i] = p2[i-1] * 2ll % mod;
  }

  dp[0][0] = 1;
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      if (dp[i][j] == 0) continue;
      for (int x=1; x<=n; x++) {
        int i2 = i == 0 ? x : i + x + 1;
        if (i2 > n) break;
        int ad = dp[i][j] * 1ll * p2[x-1] % mod;
        ad = ad * 1ll * f[j+x] % mod;
        ad = ad * 1ll * finv[x] % mod;
        ad = ad * 1ll * finv[j] % mod;
        dp[i2][j+x] = (dp[i+x+1][j+x] + ad) % mod;
      }
    }
  }

  int z = 0;
  for (int i=1; i<=n; i++) {
    z = (z + dp[n][i]) % mod;
  }

  cout << z << '\n';
}