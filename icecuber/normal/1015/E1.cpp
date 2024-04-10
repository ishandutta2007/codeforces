#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1002;
int a[nax][nax];
int dp[4][nax][nax];
int xacc[nax][nax];
int yacc[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      a[i][j] = (s[j] == '*');
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j]) {
	dp[0][i][j] = (i ? dp[0][i-1][j] : 0)+1;
	dp[1][i][j] = (j ? dp[1][i][j-1] : 0)+1;
      }
    }
  }
  for (int i = h-1; i >= 0; i--) {
    for (int j = w-1; j >= 0; j--) {
      if (a[i][j]) {
	dp[2][i][j] = (i+1 < h ? dp[2][i+1][j] : 0)+1;
	dp[3][i][j] = (j+1 < w ? dp[3][i][j+1] : 0)+1;
      }
    }
  }

  vector<tuple<int,int,int>> ans;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int mi = min({dp[0][i][j], dp[1][i][j], dp[2][i][j], dp[3][i][j]});
      if (mi >= 2) {
	ans.emplace_back(i+1, j+1, mi-1);
	xacc[i][j-mi+1]++;
	xacc[i][j+mi]--;
	yacc[i-mi+1][j]++;
	yacc[i+mi][j]--;
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j) xacc[i][j] += xacc[i][j-1];
      if (i) yacc[i][j] += yacc[i-1][j];
      //cout << (xacc[i][j] || yacc[i][j] ? '*' : '.');
      if (a[i][j] && !xacc[i][j] && !yacc[i][j]) {
	cout << -1 << endl;
	return 0;
      }
    }
    //cout << endl;
  }
  cout << ans.size() << endl;
  for (auto [a, b, c] : ans)
    cout << a << ' ' << b << ' ' << c << '\n';
}