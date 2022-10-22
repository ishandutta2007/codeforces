#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll w;
  cin >> w;
  const ll leave = 100;
  ll c[9];
  ll sum = 0, base = 0;
  for (int i = 1; i <= 8; i++) {
    cin >> c[i];
    ll take = max(min(c[i]-leave, (w-leave)/i), 0ll);
    c[i] -= take;
    w -= take*i;
    base += take*i;
    sum += c[i]*i;
  }
  if (sum <= w) {
    cout << base+sum << endl;
    return 0;
  }

  vector<int> dp(w+1,0);
  dp[0] = 1;
  for (int i = 1; i <= 8; i++) {
    for (int j = min(100ll, c[i]); j; j--) {
      for (int k = w; k >= i; k--)
	dp[k] |= dp[k-i];
    }
  }
  int best = 0;
  for (int i = 0; i <= w; i++) {
    if (dp[i]) best = i;
  }
  cout << base+best << endl;
}