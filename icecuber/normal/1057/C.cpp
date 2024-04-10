#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string c;
int r[50];

int dp[50][2000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, s, k;
  cin >> n >> s >> k;
  s--;
  int ans = 1e9;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < k; j++)
      dp[i][j] = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    if (r[i] >= k)
      ans = min(ans, abs(i-s));
    else
      dp[i][r[i]] = abs(i-s);
  }
  cin >> c;

  //dp[i][j] = minimum time to eat j candies, if last ate at position i
  for (int j = 0; j < k; j++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][j] == 1e9) continue;
      for (int b = 0; b < n; b++) {
	if (r[b] > r[i] && c[b] != c[i]) {
	  int j_ = j+r[b], t = dp[i][j]+abs(i-b);
	  if (j_ >= k) ans = min(ans, t);
	  else
	    dp[b][j_] = min(dp[b][j_], t);
	}
      }
    }
  }
  cout << (ans == 1e9 ? -1 : ans) << endl;
}