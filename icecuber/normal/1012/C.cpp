#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void umin(int&a, int b) {
  a = min(a, b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  int maxk = (n+1)/2;
  vector<vector<int>> dp(maxk+1, vector<int>(3, 1e9));
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> ndp(maxk+1, vector<int>(3, 1e9));
    for (int j = 0; j <= maxk; j++) {
      //Place
      if (j+1 <= maxk) {
	if (i >= 2) {
	  umin(ndp[j+1][0], dp[j][1]+max(min(a[i-1], a[i-2]-1)+1-a[i], 0));
	}
	umin(ndp[j+1][0], dp[j][2]+(i ? max(a[i-1]+1-a[i], 0) : 0));
      }

      //Don't place
      if (i)
	umin(ndp[j][1], dp[j][0]+max(a[i]+1-a[i-1], 0));
      umin(ndp[j][2], dp[j][1]);
      umin(ndp[j][2], dp[j][2]);
    }
    swap(ndp, dp);
  }
  for (int k = 1; k <= maxk; k++)
    cout << min({dp[k][0], dp[k][1], dp[k][2]}) << ' ';
  cout << endl;
}