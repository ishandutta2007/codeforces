#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w[20][100000];
int par[20][100000];
vector<int> child[100000];

pair<ll,ll> dp[100000];
int depth[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, L;
  ll s;
  cin >> n >> L >> s;
  for (int i = 0; i < n; i++) {
    cin >> w[0][i];
    if (w[0][i] > s) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    cin >> par[0][i];
    par[0][i]--;
    child[par[0][i]].push_back(i);
  }
  for (int l = 1; l < 20; l++) {
    for (int i = 0; i < n; i++) {
      int p = par[l-1][i];
      w[l][i] = w[l-1][i]+w[l-1][p];
      par[l][i] = par[l-1][p];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j : child[i])
      depth[j] = depth[i]+1;
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j : child[i]) {
      dp[i].second = max(dp[i].second, dp[j].second-1);
      dp[i].first += dp[j].first;
    }
    if (dp[i].second == 0) {
      int j = i, reach = 0;
      ll s_left = s;
      for (int l = 19; l >= 0; l--) {
	if (1<<l <= depth[i]+1-reach && 1<<l <= L-reach && w[l][j] <= s_left) {
	  reach += 1<<l;
	  s_left -= w[l][j];
	  j = par[l][j];
	}
      }
      dp[i].second = reach;
      dp[i].first++;
    }
  }
  cout << dp[0].first << endl;
}