#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int A[4][100];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> dp(1<<n, 0);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
	cin >> A[i][j];
    for (int j = 0; j < m; j++) {
      vector<int> ndp(1<<n, 0);
      for (int a = 0; a < 1<<n; a++) {
	for (int b = 0; b < 1<<n; b++) {
	  if ((a&b)==a) {
	    for (int r = 0; r < n; r++) {
	      int v = dp[a];
	      for (int i = 0; i < n; i++) {
		if ((b>>i&1) && !(a>>i&1))
		  v += A[(i+r)%n][j];
	      }
	      ndp[b] = max(ndp[b], v);
	    }
	  }
	}
      }
      swap(dp,ndp);
    }
    cout << dp[(1<<n)-1] << endl;
  }
}