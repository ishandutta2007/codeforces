#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int a[1500], b[1501];
pair<int, int> seg[1500];
int dp[1501][1501], reach[1500];

int main() {
  int n, s, m, k;
  cin >> n >> s >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < s; i++) {
    cin >> seg[i].x >> seg[i].y;
    seg[i].x--;
    //cout << seg[i].x << ' ' << seg[i].y << endl;
  }
  int fail = -1, pass = 1e9+1;
  while (fail+1 < pass) {
    int mid = fail+pass>>1;
    for (int i = 1; i <= n; i++)
      b[i] = b[i-1]+(a[i-1]<=mid);

    for (int i = 0; i <= b[n]; i++) {
      reach[i] = i;
      for (int j = 0; j < s; j++)
	if (b[seg[j].y] >= i)
	  reach[i] = min(reach[i], b[seg[j].x]);
    }
    int best = 0;
    for (int i = 1; i <= b[n]; i++)
      for (int j = i; j; j--) {
	if (j==i) dp[i][j] = 1e9;
	else
	  dp[i][j] = min(dp[i-1][j], dp[i][j+1]);
	if (j-(i-reach[i]) >= 0)
	  dp[i][j] = min(dp[i][j], dp[reach[i]][j-(i-reach[i])]+1);

	if (dp[i][j] <= m) best = max(best,j);
	//if (mid == 1e9) cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << reach[i] << endl;
      }

    if (best >= k) pass = mid;
    else fail = mid;
  }
  if (pass == 1e9+1) pass = -1;
  cout << pass << endl;
}