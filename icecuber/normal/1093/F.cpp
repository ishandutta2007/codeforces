#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 998244353;
int a[100001];
ll dp[100001][100], dp_sum[100001];

int main() {
  ios::sync_with_stdio(0);
  int n, k, m;
  cin >> n >> k >> m;
  map<int,int> s;
  dp_sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i-1];
    a[i-1]--;
    dp_sum[i] = 0;
    if (a[i-1] != -2) s[a[i-1]]++;
    if (i >= m+1 && a[i-m-1] != -2 && !--s[a[i-m-1]])
      s.erase(a[i-m-1]);
    for (int j = 0; j < k; j++) {
      if (a[i-1] == -2 || j == a[i-1]) {
	dp[i][j] = dp_sum[i-1];
	if ((s.size() == 0 || s.size() == 1 && s.begin()->first == j) && i >= m)
	  dp[i][j] = (dp[i][j]-(dp_sum[i-m]-dp[i-m][j]))%mod;
      }
      //cout << i << ' ' << j+1 << ' ' << dp[i][j] << endl;
      dp_sum[i] = (dp_sum[i]+dp[i][j])%mod;
    }
  }
  cout << (dp_sum[n]%mod+mod)%mod << endl;
}