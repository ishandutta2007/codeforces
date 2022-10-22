#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1001][51][51];
int nexta[51][26];
int nextb[51][26];

void build(string s, int dp[][26]) {
  for (int i = 0; i <= s.size(); i++) {
    for (int c = 0; c < 26; c++) {
      string target = s.substr(0,i)+char(c+'a');
      for (int j = min(i+1, int(s.size())); j >= 0; j--) {
	if (s.substr(0,j) == target.substr(target.size()-j, j)) {
	  dp[i][c] = j;
	  break;
	}
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s, a, b;
  cin >> s >> a >> b;
  build(a, nexta);
  build(b, nextb);
  for (int i = 0; i <= s.size(); i++)
    for (int j = 0; j <= a.size(); j++)
      for (int k = 0; k <= b.size(); k++)
	dp[i][j][k] = -1e9;
  dp[0][0][0] = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= a.size(); j++) {
      for (int k = 0; k <= b.size(); k++) {
	for (int c = 0; c < 26; c++) {
	  if (c+'a' != s[i] && s[i] != '*') continue;
	  int na = nexta[j][c];
	  int nb = nextb[k][c];
	  int&d = dp[i+1][na][nb];
	  d = max(d, dp[i][j][k]+(na==a.size())-(nb==b.size()));
	}
      }
    }
  }
  int ans = -1e9;
  for (int j = 0; j <= a.size(); j++)
    for (int k = 0; k <= b.size(); k++)
      ans = max(ans, dp[s.size()][j][k]);
  cout << ans << endl;
}