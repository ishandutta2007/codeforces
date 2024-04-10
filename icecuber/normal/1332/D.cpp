#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
const int nax = 510;
int dp[nax][nax];
int a[nax][nax] = {{7,3,3,1},{4,8,3,6},{7,7,7,3}};
int f(int w, int h) {
  fill_n((int*)dp, nax*nax, 0);
  dp[0][1] = a[0][0];
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++)
      dp[i][j] = max(dp[i-1][j]&a[i-1][j-1], dp[i][j-1]&a[i-1][j-1]);
  return dp[h][w];
}
*/

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k;
  cin >> k;
  cout << 2 << ' ' << 3 << endl;
  int m = 1<<17, a = 2*m-1;
  cout << a << ' ' << k << ' ' << 0 << endl;
  cout << m << ' ' << a << ' ' << k << endl;
  /*int w = 4, h = 3;
  cout << f(w,h) << endl;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++)
      cout << dp[i][j] << ' ';
    cout << endl;
    }*/
}