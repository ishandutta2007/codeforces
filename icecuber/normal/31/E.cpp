#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[19][19];
char par[19][19];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  //dp[i][j] = max value with i Hs and j Ms
  ll pow10[20] = {1};
  for (int i = 0; i < n; i++)
    pow10[i+1] = 10*pow10[i];
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      ll v;
      if (i < n && (v=dp[i][j]+pow10[n-1-i]*(s[i+j]-'0')) > dp[i+1][j]) {
	dp[i+1][j] = v;
	par[i+1][j] = 'H';
      }
      if (j < n && (v=dp[i][j]+pow10[n-1-j]*(s[i+j]-'0')) > dp[i][j+1]) {
	dp[i][j+1] = v;
	par[i][j+1] = 'M';
      }
    }
  }
  int i = n, j = n;
  string ans;
  while (i+j) {
    ans += par[i][j];
    if (par[i][j] == 'H') i--;
    else j--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}