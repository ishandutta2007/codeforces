#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double C, T;
    cin >> C >> T;
    vector<pair<int,int>> ap(n);
    ll max_points = 0;
    for (auto&p : ap) {
      cin >> p.first >> p.second;
      max_points += p.second;
    }
    sort(ap.rbegin(), ap.rend());

    //dp[i][j][k] = minimum untrained solving time, up to problem i, giving j points, using k problems
    vector<vector<double>> dp(max_points+1, vector<double>(n+1,1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      vector<vector<double>> ndp = dp;
      for (int j = 0; j <= max_points-ap[i].second; j++) {
	double p09 = 1;
	for (int k = 0; k < n; k++) {
	  p09 *= (1./0.9);
	  double new_time = dp[j][k]+p09*ap[i].first;
	  double&ndp_ = ndp[j+ap[i].second][k+1];
	  ndp_ = min(ndp_, new_time);
	}
      }
      swap(dp,ndp);
    }
    for (int j = max_points; j >= 0; j--) {
      for (int k = 0; k <= n; k++) {
	double T_ = T-k*10;
	if (T_*C >= 1 && pow(T_*C-1,2) >= 4*C*(dp[j][k]-T_) || dp[j][k] <= T_) {
	  cout << j << endl;
	  goto done;
	}
      }
    }
    done:;
  }
}