#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 59;
int prime[M], primes = 0;
int mask[M];

int dp[101][1<<16];
int par[101][1<<16];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < M; i++) {
    for (int j = 0; j < primes; j++) {
      if (i%prime[j] == 0)
	mask[i] |= 1<<j;
    }
    if (!mask[i]) {
      mask[i] |= 1<<primes;
      prime[primes++] = i;
    }
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fill_n(dp[i+1], 1<<primes, 1e9);
    for (int b = 1; b < M; b++) {
      for (int j = 0; j < 1<<primes; j++) {
	if ((mask[b]&j) == 0) {
	  int&d = dp[i+1][mask[b]|j];
	  int dd = dp[i][j]+abs(b-a);
	  if (dd < d) {
	    d = dd;
	    par[i+1][mask[b]|j] = b;
	  }
	}
      }
    }
  }
  int best = 1e9, p;
  for (int i = 0; i < 1<<primes; i++)
    if (dp[n][i] < best)
      best = dp[n][i], p = i;

  vector<int> ans;
  for (int i = n; i; i--) {
    ans.push_back(par[i][p]);
    p ^= mask[par[i][p]];
  }
  reverse(ans.begin(), ans.end());
  for (int v : ans)
    cout << v << ' ';
  cout << endl;
}