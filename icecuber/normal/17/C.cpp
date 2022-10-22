#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int mod = 51123987;
void self_add(int&a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = (n-1)/3+1;
  vvvi dp(m+1,vvi(m+1,vi(m+1,0))), last[3] = {dp,dp,dp};
  dp[0][0][0] = 1;
  for (char si : s) {
    for (int it = 0; it <= 0; it++) {
      vvvi ndp = dp;
      vvvi acc(m+1,vvi(m+1,vi(m+1,0)));
      for (int a = 0; a <= m; a++) {
	for (int b = 0; b <= m; b++) {
	  for (int c = 0; c <= m; c++) {
	    int a_ = a-(si=='a'), b_ = b-(si=='b'), c_ = c-(si=='c');
	    if (a_ >= 0 && b_ >= 0 && c_ >= 0) {
	      self_add(acc[a][b][c], dp[a_][b_][c_]);
	      self_add(acc[a][b][c], mod-last[si-'a'][a_][b_][c_]);
	      self_add(acc[a][b][c], acc[a_][b_][c_]);
	    }
	    //if (ndp[a][b][c])
	    //  cout << a << ' ' << b << ' ' << c << ' ' << ndp[a][b][c] << endl;
	  }
	}
      }
      for (int a = 0; a <= m; a++)
	for (int b = 0; b <= m; b++)
	  for (int c = 0; c <= m; c++)
	    self_add(ndp[a][b][c], acc[a][b][c]);

      last[si-'a'] = ndp;
      //cout << endl;
      swap(dp,ndp);
    }
  }

  int ans = 0;
  for (int a = 0; a <= m; a++)
    for (int b = 0; b <= m; b++)
      for (int c = 0; c <= m; c++) {
	if (a+b+c == n && abs(a-b) <= 1 && abs(a-c) <= 1 && abs(b-c) <= 1) {
	  //cout << a << ' ' << b << ' ' << c << ' ' << dp[a][b][c] << endl;
	  self_add(ans, dp[a][b][c]);
	}
      }
  cout << ans << endl;
}