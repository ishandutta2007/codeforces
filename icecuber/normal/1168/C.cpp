#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 20;
int a[300010];
int dp[300010][m], ne[300010][m];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int j = 0; j < m; j++) {
    ne[n][j] = n;
    dp[n][j] = n;
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (a[i]>>j&1) {
	ne[i][j] = i;
	dp[i][j] = i;
      } else {
	ne[i][j] = ne[i+1][j];
	dp[i][j] = n;
      }
    }
    for (int j = 0; j < m; j++) {
      if (!(a[i]>>j&1)) continue;
      for (int k = 0; k < m; k++) {
	int next = ne[i+1][j];
	if (next < n)
	  dp[i][k] = min(dp[i][k], dp[next][k]);
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int ok = 0;
    for (int j = 0; j < m; j++)
      if ((a[y]>>j&1) && dp[x][j] <= y) ok = 1;
    cout << (ok ? "Shi" : "Fou") << endl;
  }
}