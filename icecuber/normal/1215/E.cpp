#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[400000];
ll A[20][20], B[20][20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int tot[20] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    tot[a[i]]++;
  }

  int c[20] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      A[j][a[i]] += c[j];
      B[a[i]][j] += tot[j]-c[j];
    }
    c[a[i]]++;
  }

  vector<ll> dp(1<<20,0);
  for (int i = 1; i < 1<<20; i++) {
    dp[i] = 1e18;
    for (int j = 0; j < 20; j++) {
      if (i>>j&1) {
	int i_ = i^1<<j;
	ll x = dp[i_], y = x;
	for (int k = 0; k < 20; k++) {
	  if (i_>>k&1) {
	    x += A[k][j];
	    y += B[j][k];
	  }
	}
	dp[i] = min({dp[i], x,y});
      }
    }
  }
  cout << dp[(1<<20)-1] << endl;
}