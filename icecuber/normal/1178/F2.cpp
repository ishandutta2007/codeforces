#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1001][1001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  vector<vector<int>> pos(n);
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    c[i]--;
    pos[c[i]].push_back(i);
  }
  vector<int> p(n*2);
  for (int i = 0; i < n; i++) {
    p[i*2] = pos[i][0];
    p[i*2+1] = pos[i].back()+1;
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end())-p.begin());

  for (int i = 0; i < p.size(); i++) {
    dp[i][i] = 1;
  }

  ll mod = 998244353;
  for (int k = n-1; k >= 0; k--) {
    int a = pos[k][0], b = pos[k].back()+1;
    for (int i = a; i < b; i++)
      if (c[i] < k) {
	cout << 0 << endl;
	return 0;
      }

    int s = a, e = b;
    while (s && c[s-1] > k) s--;
    while (e < m && c[e] > k) e++;

    a = lower_bound(p.begin(), p.end(), a)-p.begin();
    b = lower_bound(p.begin(), p.end(), b)-p.begin();
    s = lower_bound(p.begin(), p.end(), s)-p.begin();
    e = upper_bound(p.begin(), p.end(), e)-p.begin()-1;

    ll ways = 1;
    for (int i = 0; i+1 < pos[k].size(); i++) {
      int u = pos[k][i]+1, v = pos[k][i+1];
      int x = lower_bound(p.begin(), p.end(), u)-p.begin();
      int y = lower_bound(p.begin(), p.end(), v)-p.begin();
      //(ways *= dp[u][v]) %= mod;
      //if (p[x] != u || p[y] != v) {
      //cout << dp[u][v] << ' ' << u << ' ' << v << endl;
      //}
      if (p[x] == u && p[y] == v)
	(ways *= dp[x][y]) %= mod;
      else
	ways *= (u==v);
    }

    vector<ll> left(p.size(),0), right(p.size(),0);
    for (int l = s; l <= a; l++) {
      for (int m = l; m <= a; m++) {
	(left[l] += dp[l][m]*dp[m][a]) %= mod;
      }
    }
    for (int r = b; r <= e; r++) {
      for (int m = b; m <= r; m++) {
	(right[r] += dp[b][m]*dp[m][r]) %= mod;
      }
    }

    for (int l = s; l <= a; l++) {
      for (int r = b; r <= e; r++) {
	dp[l][r] = ways * left[l] % mod * right[r] % mod;
      }
    }
  }
  /*for (int l = 0; l <= m; l++)
    for (int r = l+1; r <= m; r++)
      if (dp[l][r] && (!binary_search(p.begin(), p.end(), l) || !binary_search(p.begin(), p.end(), r))) {
	cout << l << ' ' << r << endl;
	assert(0);
	//cout << l << ' ' << r << ' ' << dp[l][r] << endl;
	}*/
  cout << dp[0][(p.size()-1)] << endl;
}