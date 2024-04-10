#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow2(ll a) {
  return a*a;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<int>> w(3);
    for (int k = 0; k < 3; k++) {
      w[k].resize(n[k]);
      for (int&wi : w[k]) cin >> wi;
      sort(w[k].begin(), w[k].end());
    }
    sort(w.begin(), w.end());
    ll ans = 8e18;
    do {
      int j = 0, k = -1;
      for (int i = 0; i < (int)w[0].size(); i++) {
	while (j < (int)w[1].size() && w[1][j] < w[0][i]) j++;
	if (j == (int)w[1].size()) break;
	while (k+1 < (int)w[2].size() && w[2][k+1] <= w[0][i]) k++;

	if (k == -1) continue;
	ll x = w[0][i], y = w[1][j], z = w[2][k];
	ans = min(ans, pow2(x-y)+pow2(y-z)+pow2(z-x));
      }
    } while (next_permutation(w.begin(), w.end()));
    cout << ans << endl;
  }
}