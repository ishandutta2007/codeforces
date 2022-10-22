#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define get glkjerg
const int nax = 5001;
int need[nax], get[nax], weight[nax];
int reach[nax];
vector<int> weights[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> need[i] >> get[i] >> weight[i];
  }
  fill_n(reach, n, -1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    reach[b] = max(reach[b], a);
  }
  for (int i = 0; i < n; i++) {
    if (reach[i] != -1) {
      weights[reach[i]].push_back(weight[i]);
    } else {
      weights[i].push_back(weight[i]);
    }
  }

  vector<int> dp(nax, -1e9);
  dp[k] = 0;
  for (int i = 0; i < n; i++) {
    {
      vector<int> ndp(nax, -1e9);
      for (int j = 0; j < nax; j++) {
	if (j >= need[i] && j+get[i] < nax) {
	  ndp[j+get[i]] = dp[j];
	}
      }
      dp = ndp;
    }
    for (int w : weights[i]) {
      vector<int> ndp = dp;
      for (int j = 0; j+1 < nax; j++) {
	ndp[j] = max(ndp[j], dp[j+1]+w);
      }
      dp = ndp;
    }
  }
  int ans = *max_element(dp.begin(), dp.end());
  cout << max(-1, ans) << endl;
}