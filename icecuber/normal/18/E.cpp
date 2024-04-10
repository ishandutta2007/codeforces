#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 26;
int c[500][2][26];
tuple<int,int> par[500][26][26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++)
      c[i][j%2][s[j]-'a']++;
    for (int k = 0; k < 2; k++)
      for (int j = 0; j < m; j++)
	c[i][k][j] = (w+!k)/2-c[i][k][j];
  }
  //dp[i][a][b] = minimum cost until i if for i is abab...
  vector<vector<int>> dp(m, vector<int>(m,0));
  for (int i = 0; i < h; i++) {
    vector<vector<int>> ndp(m, vector<int>(m,1e9));
    for (int a = 0; a < m; a++) {
      for (int b = 0; b < m; b++) {
	if (a == b) continue;
	for (int na = 0; na < m; na++) {
	  if (na == a) continue;
	  for (int nb = 0; nb < m; nb++) {
	    if (nb == b || na == nb) continue;
	    int v = dp[a][b]+c[i][0][na]+c[i][1][nb];
	    if (v < ndp[na][nb]) {
	      ndp[na][nb] = v;
	      par[i][na][nb] = {a,b};
	    }
	  }
	}
      }
    }
    swap(dp,ndp);
  }
  int ans = 1e9, besta, bestb;
  for (int a = 0; a < 26; a++)
    for (int b = 0; b < 26; b++) {
      if (dp[a][b] < ans) {
	ans = dp[a][b];
	besta = a;
	bestb = b;
      }
    }
  cout << ans << endl;
  vector<string> path;
  int a = besta, b = bestb;
  for (int i = h-1; i >= 0; i--) {
    string s;
    for (int j = 0; j < w; j++)
      s += char((j%2 ? b : a)+'a');
    path.push_back(s);
    tie(a,b) = par[i][a][b];
  }
  reverse(path.begin(), path.end());
  for (string s : path) cout << s << endl;
}