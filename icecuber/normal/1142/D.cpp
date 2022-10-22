#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f_a[11][11][11][10];
int f_b[11][11][11][10];
int f_c[11][11][11][10];

int last_dp[11][11][11];
int dp[11][11][11];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  /*map<int,int> m;
  for (int i = 1; i < 10; i++)
    m[i] = i;
  int c = 0;
  for (auto p : m) {
    if (c++ == 10000) break;
    //cout << p.first << ' ';
    int k = p.second;
    for (int i = 0; i < k%11; i++) {
      int next_index = m.size()+1;
      m[p.first*10+i] = next_index;
    }
  }
  cout << endl;
  */
  for (int a = 0; a < 11; a++)
    for (int b = 0; b < 11; b++)
      for (int c = 0; c < 11; c++)
	for (int r = 0; r < 10; r++) {
	  f_a[a][b][c][r] = ((a+c+b*(2*a-b-1)/2+r+1)%11+11)%11;
	  f_b[a][b][c][r] = ((b*(2*a-b-1)/2+r)%11+11)%11;
	  f_c[a][b][c][r] = ((a-r-1+c*(2*a+c+1)/2)%11+11)%11;
	}

  string s;
  cin >> s;
  ll ans = 0;
  for (char c : s) {
    int r = c-'0';
    fill_n((int*)dp, 11*11*11, 0);
    if (r)
      dp[r][r-1][9-r]++, ans++;
    for (int a = r+1; a < 11; a++)
      for (int b = 0; b < 11; b++)
	for (int c = 0; c < 11; c++) {
	  dp[f_a[a][b][c][r]]
	    [f_b[a][b][c][r]]
	    [f_c[a][b][c][r]] += last_dp[a][b][c];
	  ans += last_dp[a][b][c];
	}
    copy_n((int*)dp, 11*11*11, (int*)last_dp);
  }
  cout << ans << endl;
}