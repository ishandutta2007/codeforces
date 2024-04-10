#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 100;
ll dp[nax][nax], par[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<array<int,3>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][1] >> a[i][0];
      a[i][2] = i+1;
    }
    sort(a.begin(), a.end());
    fill_n((ll*)dp, nax*nax, -1e18);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (dp[i][j] < 0) continue;
	{
	  //Pick
	  ll score = dp[i][j]+j*a[i][0]+a[i][1];
	  if (score > dp[i+1][j+1]) {
	    dp[i+1][j+1] = score;
	    par[i+1][j+1] = 1;
	  }
	}
	{
	  //Don't pick
	  ll score = dp[i][j]+(k-1)*a[i][0];
	  if (score > dp[i+1][j]) {
	    dp[i+1][j] = score;
	    par[i+1][j] = 0;
	  }
	}
      }
    }
    {
      //cout << dp[n][k] << endl;
      assert(dp[n][k] >= 0);
      int j = k;
      vector<int> picks;
      vector<int> free(n, 1);
      for (int i = n; i > 0; i--) {
	if (par[i][j]) {
	  picks.push_back(i-1);
	  free[i-1] = 0;
	  j--;
	}
      }
      assert(j == 0);
      reverse(picks.begin(), picks.end());
      cout << k+(n-k)*2 << endl;
      for (int i = 0; i < k-1; i++)
	cout << a[picks[i]][2] << ' ';
      for (int i = 0; i < n; i++) {
	if (free[i]) {
	  cout << a[i][2] << ' ';
	  cout <<-a[i][2] << ' ';
	}
      }
      cout << a[picks.back()][2] << endl;
    }
  }
}