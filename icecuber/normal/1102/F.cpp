#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[16][10000];

int adj[16][16];
int adj2[16][16];

int dp[16][16][1<<16];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      adj[i][j] = 2e9;
      for (int k = 0; k < m; k++)
	adj[i][j] = min(adj[i][j], abs(a[i][k]-a[j][k]));

      adj2[i][j] = 2e9;
      for (int k = 0; k < m-1; k++)
	adj2[i][j] = min(adj2[i][j], abs(a[i][k+1]-a[j][k]));
    }
  int ans = 0;
  for (int i = 0; i < 1<<n; i++) {
    for (int s = 0; s < n; s++) {
      if (!(i>>s&1)) continue;
      for (int e = 0; e < n; e++) {
	if (!(i>>e&1)) continue;
	if (i == (1<<s) && i == (1<<e))
	  dp[s][e][i] = 2e9;
	else {
	  int i_ = i^1<<e;
	  for (int j = 0; j < n; j++) {
	    if (!(i_>>j&1)) continue;
	    int v = min(dp[s][j][i_], adj[j][e]);
	    dp[s][e][i] = max(dp[s][e][i], v);
	  }
	}
	if (i == (1<<n)-1) {
	  ans = max(ans, min(dp[s][e][i], adj2[s][e]));
	}
      }
    }
  }
  cout << ans << endl;
}