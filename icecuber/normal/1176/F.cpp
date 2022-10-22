#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> dp(10,-1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    vector<ll> new_dp = dp; //Play zero cards
    int k;
    cin >> k;
    vector<ll> cards[4];
    while (k--) {
      int c, d;
      cin >> c >> d;
      cards[c].push_back(d);
    }
    for (int i = 1; i < 4; i++) {
      cards[i].push_back(-1e18);
      cards[i].push_back(-1e18);
      cards[i].push_back(-1e18);
      sort(cards[i].rbegin(), cards[i].rend());
    }

    for (int j = 0; j < 10; j++) {
      {
	//Play 1 card
	ll dmg = max({cards[1][0], cards[2][0], cards[3][0]})*(1+(j==9));
	ll&d = new_dp[(j+1)%10];
	d = max(d, dmg+dp[j]);
      }
      {
	//Play 2 cards
	ll dmg = cards[1][0]+max(cards[1][1], cards[2][0]);
	if (j >= 8)
	  dmg += max(cards[1][0], max(cards[1][1], cards[2][0]));
	ll&d = new_dp[(j+2)%10];
	d = max(d, dmg+dp[j]);
      }
      {
	ll dmg = cards[1][0]+cards[1][1]+cards[1][2];
	if (j >= 7)
	  dmg += cards[1][0];
	//Play 3 cards
	ll&d = new_dp[(j+3)%10];
	d = max(d, dmg+dp[j]);
      }
    }
    dp = new_dp;
  }
  ll ans = 0;
  for (int i = 0; i < 10; i++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
}