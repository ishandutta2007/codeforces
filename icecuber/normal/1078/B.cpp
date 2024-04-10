#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = (1LL<<48)-5;
int a[100];
ll dp[101][10001];
ll ncr[101][101];
ll good[101][10001];

int main() {
  ncr[0][0] = 1;
  for (int n = 1; n <= 100; n++) {
    ncr[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      ncr[n][k] = ncr[n-1][k-1]+ncr[n-1][k];
      if (ncr[n][k] >= mod) ncr[n][k] -= mod;
    }
  }
  map<int, int> count;
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    count[a[i]]++;
    sum += a[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int k = n-1; k >= 0; k--)
      for (int j = sum-a[i]; j >= 0; j--)
	(dp[k+1][j+a[i]] += dp[k][j]) %= mod;
  }
  for (auto p : count) {
    int w = p.first;
    int c = p.second;
    for (int i = 1; i <= c; i++) {
      if (dp[i][w*i] == ncr[c][i]) {
	//cout << w << ' ' << i << endl;
	good[i][w*i] = 1;
      }
    }
  }
  int best = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sum; j++) {
      //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      int v = 0;
      if (good[i][j]) v += i;
      if (good[n-i][sum-j]) v += n-i;
      best = max(best, v);
    }

  cout << best << endl;
}