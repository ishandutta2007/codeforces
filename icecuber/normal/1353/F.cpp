#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll hmap[110][110];
ll dp[110][110];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    vector<ll> h_list;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
	cin >> hmap[i][j];
	hmap[i][j] -= i+j;
	h_list.push_back(hmap[i][j]);
      }
    ll ans = 1e18;
    for (ll base : h_list) {
      for (int i = 0; i < h; i++) {
	for (int j = 0; j < w; j++) {
	  if (hmap[i][j] < base) {
	    dp[i][j] = 1e18;
	  } else {
	    dp[i][j] = min(i ? dp[i-1][j] : (ll)1e18,
			   j ? dp[i][j-1] : (ll)1e18)+hmap[i][j]-base;
	    if (i == 0 && j == 0)
	      dp[i][j] = hmap[i][j]-base;
	  }
	}
      }
      ans = min(ans, dp[h-1][w-1]);
    }
    cout << ans << endl;
  }
}