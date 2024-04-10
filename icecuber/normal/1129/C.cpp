#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7, base = 3, hmod = (1ll<<61)+5;
ll h[3000][3001], dp[3000][3001];

ll ans[3001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    s += c;
  }
  string taboo[4] = {"0011","0101","1110","1111"};
  for (int l = n-1; l >= 0; l--) {
    dp[l][l] = 1;
    for (int r = l+1; r <= n; r++) {
      h[l][r] = (h[l][r-1]*base+(s[r-1]=='1'?2:1)) % hmod;
      for (int i = 1; i <= 3; i++)
	if (r-i >= l)
	  (dp[l][r] += dp[l][r-i]) %= mod;
      int ok = r-4 >= l;
      for (int i = 0; ok && i < 4; i++)
	if (s.substr(r-4,4) == taboo[i]) ok = 0;
      if (ok) (dp[l][r] += dp[l][r-4]) %= mod;
    }
  }

  unordered_set<ll> seen;
  seen.reserve(1e4);
  for (int d = 1; d <= n; d++) {
    seen.clear();
    for (int r = d; r <= n; r++) {
      int l = r-d;
      if (!seen.count(h[l][r])) {
	(ans[r] += dp[l][r]) %= mod;
	seen.insert(h[l][r]);
      }
    }
  }
  ll tot = 0;
  for (int r = 1; r <= n; r++) {
    (tot += ans[r]) %= mod;
    cout << tot << endl;
  }
}