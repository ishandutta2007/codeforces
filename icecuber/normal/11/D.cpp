#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1<<19][19];
int adj[19][19];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a][b] = adj[b][a] = 1;
  }
  ll ans = 0;
  //dp[a][i][b] = number of paths from a to b using nodes in i
  for (int a = 0; a < n; a++) {
    for (int i = 0; i < 1<<n; i++)
      for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int i = 0; i < 1<<n; i++) {
      if (i>>a != 1) continue;
      if (i == 1<<a) dp[i][a] = 1;
      for (int b = 0; b <= a; b++) {
	if (!(i>>b&1)) continue;
	if (adj[b][a] && __builtin_popcount(i) >= 3) ans += dp[i][b];
	for (int c = 0; c < a; c++) {
	  if ((i>>c&1) || !adj[b][c]) continue;
	  dp[i|1<<c][c] += dp[i][b];
	}
      }
    }
  }
  cout << ans/2 << endl;
}