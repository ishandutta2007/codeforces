#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e6+10;
int cnt[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int&v : a) {
    cin >> v;
    cnt[v]++;
  }
  vector<ll> b(nax), c(nax);
  for (int i = 1; i < nax; i++) {
    b[i] = b[i-1]+cnt[i-1];
    c[i] = c[i-1]+b[i];
  }
  ll ans = 1e18;
  for (int d = 2; d < nax/2; d++) {
    ll tot = 0;
    for (int i = 0; i < nax/2; i += d) {
      /*ll v = 0;
      for (int j = i+1; j < i+d; j++) {
	v += min(x, (i+d-j)*y) * cnt[j];
	}*/

      int k = min((int)(x/y), d-1);

      ll v3 = 0;
      /*for (int j = 1; j <= k; j++) {
	v3 += j*y * cnt[i+d-j];
      }
      for (int j = k+1; j < d; j++) {
	v3 += x * cnt[i+d-j];
	}*/

      v3 += y * (c[i+d] - c[i+d-k] - b[i+d-k] * k);
      v3 += x * (b[i+d-k] - b[i+1]);

      //assert(v == v3);
      tot += v3;
    }
    ans = min(ans, tot);
  }
  cout << ans << endl;
}