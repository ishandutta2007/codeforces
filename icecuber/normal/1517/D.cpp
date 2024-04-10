#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 500;
int dp[11][nax][nax];
int hori[nax][nax], vert[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w, K;
  cin >> h >> w >> K;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w-1; j++)
      cin >> hori[i][j];
  for (int i = 0; i < h-1; i++)
    for (int j = 0; j < w; j++)
      cin >> vert[i][j];

  if (K%2) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << -1 << ' ';
      }
      cout << endl;
    }
    return 0;
  }
  for (int k = 1; k <= K/2; k++) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[k][i][j] = 1e9;
        if (i)
          dp[k][i][j] = min(dp[k][i][j], dp[k-1][i-1][j] + vert[i-1][j]);
        if (j)
          dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][j-1] + hori[i][j-1]);
        if (i+1 < h)
          dp[k][i][j] = min(dp[k][i][j], dp[k-1][i+1][j] + vert[i][j]);
        if (j+1 < w)
          dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][j+1] + hori[i][j]);
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++)
      cout << dp[K/2][i][j]*2 << ' ';
    cout << endl;
  }
}