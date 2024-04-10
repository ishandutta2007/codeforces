#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define For(i,n) for (int i = 0; i < (n); i++)
int dist[15][15];
int dp[1<<15];
int has_edge[15];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  For(i,n) For(j,n)
    dist[i][j] = 1e9;

  has_edge[0] = 1;

  int deg = 0;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
    deg ^= 1<<a;
    deg ^= 1<<b;
    has_edge[a] = has_edge[b] = 1;
    sum += c;
  }

  For(k,n) For(i,n) For(j,n)
    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

  For(i,n) For(j,n) {
    if (has_edge[i] && has_edge[j] && i != j && dist[i][j] == 1e9) {
      cout << -1 << endl;
      return 0;
    }
  }

  fill_n(dp, 1<<n, 1e9);
  dp[deg] = 0;
  for (int i = (1<<n)-1; i; i--) {
    if (dp[i] == 1e9) continue;
    int a = 0;
    while ((i>>a&1) == 0) a++;
    for (int b = a+1; b < n; b++)
      if (i>>b&1) {
	int&d = dp[i^1<<a^1<<b];
	d = min(d, dp[i]+dist[a][b]);
      }
  }
  cout << sum+dp[0] << endl;
}