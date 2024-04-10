#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<vector<pair<int,int>>> reach(n+1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      reach[max(i-k,0)].push_back({min(i+k+1,n), i+1});
    } else {
      reach[i].push_back({i+1, i+1});
    }
  }

  vector<ll> dp(n+1,1e18);
  dp[0] = 0;

  deque<pair<int,ll>> st;
  for (int i = 0; i <= n; i++) {
    while (st.size() && st.front().first < i) st.pop_front();
    if (st.size()) {
      dp[i] = min(dp[i], st.front().second);
    }
    for (auto p : reach[i]) {
      int e;
      ll cost;
      tie(e,cost) = p;
	cost += dp[i];
      if (e == i+1) {
	dp[e] = min(dp[e], cost);
      } else {
	while (st.size() && st.back().second >= cost) st.pop_back();
	st.push_back({e,cost});
      }
      //for (int j = i; j <= e; j++)
      //dp[j] = min(dp[j], dp[i]+cost);
    }
  }
  cout << dp[n] << endl;
}