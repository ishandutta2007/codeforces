#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

struct Offer {
  ll a, b, k;
};
bool operator<(Offer a, Offer b) {
  return a.b > b.b;
}

Offer o[500];
ll dp[501][501];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> o[i].a >> o[i].b >> o[i].k;
  sort(o,o+n);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i-1][0]+max(0ll,o[i-1].a-o[i-1].k*o[i-1].b);
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(dp[i-1][j]+max(0ll,o[i-1].a-o[i-1].k*o[i-1].b),
		     dp[i-1][j-1]+o[i-1].a-(j-1)*o[i-1].b);
      dp[i][j] = max(dp[i][j], dp[i][j-1]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << endl;
}