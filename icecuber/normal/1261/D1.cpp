#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll bin_pow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = r*a%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll ncr[2001][2001];

int main() {
  for (int n = 0; n < 2001; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      ncr[n][k] = ncr[n-1][k-1]+ncr[n-1][k];
      if (ncr[n][k] >= mod)
	ncr[n][k] -= mod;
    }
  }
  assert(ncr[6][2] == 15);
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
    cin >> h[i];
  int d = 0;
  ll keq = 1;
  for (int i = 0; i < n; i++) {
    if (h[i] != h[(i+1)%n]) {
      d++;
    } else {
      keq = keq*k%mod;
    }
  }

  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  for (int a = 0; a <= n; a++) {
    for (int b = a+1; b <= n; b++) {
      if (d < a+b) continue;
      (ans += keq*bin_pow(k-2, d-a-b)%mod*ncr[d][a]%mod*ncr[d-a][b]%mod) %= mod;
    }
  }
  cout << ans << endl;
}