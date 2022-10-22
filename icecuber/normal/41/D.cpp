#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int peas[100][100];
int dp[100][100][11];
char par[100][100][11];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, k;
  cin >> h >> w >> k;
  k++;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      peas[i][j] = s[j]-'0';
      for (int l = 0; l < k; l++)
	dp[i][j][l] = -1e9;
    }
  }
  for (int j = 0; j < w; j++) {
    dp[0][j][peas[0][j]%k] = peas[0][j];
  }
  for (int i = 0; i < h-1; i++) {
    for (int j = 0; j < w; j++) {
      for (int l = 0; l < k; l++) {
	if (dp[i][j][l] == -1e9) continue;
	if (j) {
	  int p = dp[i][j][l]+peas[i+1][j-1];
	  if (p > dp[i+1][j-1][p%k]) {
	    dp[i+1][j-1][p%k] = p;
	    par[i+1][j-1][p%k] = 'R';
	  }
	}
	if (j+1 < w) {
	  int p = dp[i][j][l]+peas[i+1][j+1];
	  if (p > dp[i+1][j+1][p%k]) {
	    dp[i+1][j+1][p%k] = p;
	    par[i+1][j+1][p%k] = 'L';
	  }
	}
      }
    }
  }

  int ans = -1, startj;
  for (int j = 0; j < w; j++) {
    if (dp[h-1][j][0] > ans) {
      ans = dp[h-1][j][0];
      startj = j;
    }
  }
  cout << ans << endl;
  if (ans == -1) {
    return 0;
  }
  cout << startj+1 << endl;
  {
    string path;
    int j = startj, l = 0;
    for (int i = h-1; i; i--) {
      char c = par[i][j][l];
      path += c;
      l = ((l-peas[i][j])%k+k)%k;
      if (c == 'L') j--;
      else j++;
    }
    cout << path << endl;
  }
}