#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Par {
  int a, b, k;
  char c;
};

int dp[201][201][300];
Par par[201][201][300];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string sa, sb;
  cin >> sa >> sb;
  //dp[a][b][k] = min lengths to be at height k
  fill_n((int*)dp, 201*201*300, 1e9);
  dp[0][0][0] = 0;
  for (int a = 0; a <= sa.size(); a++) {
    for (int b = 0; b <= sb.size(); b++) {
      for (int k = 0; k < 300; k++) {
	{
	  // Put (
	  int na = a, nb = b, nk = k+1;
	  if (a < sa.size() && sa[a] == '(') na++;
	  if (b < sb.size() && sb[b] == '(') nb++;
	  if (nk < 300) {
	    int v = dp[a][b][k]+1;
	    if (v < dp[na][nb][nk]) {
	      dp[na][nb][nk] = v;
	      par[na][nb][nk] = {a, b, k, '('};
	    }
	  }
	}
	{
	  // Put )
	  int na = a, nb = b, nk = k-1;
	  if (a < sa.size() && sa[a] == ')') na++;
	  if (b < sb.size() && sb[b] == ')') nb++;
	  int v = dp[a][b][k]+1;
	  if (nk < 0) {
	    nk = 0;
	    v++;
	  }
	  if (v < dp[na][nb][nk]) {
	    dp[na][nb][nk] = v;
	    par[na][nb][nk] = {a, b, k, ')'};
	  }
	}
      }
    }
  }
  {
    int ans = 1e9, a = sa.size(), b = sb.size(), k;
    for (int i = 0; i < 300; i++) {
      if (dp[sa.size()][sb.size()][i]+i < ans) {
	ans = dp[sa.size()][sb.size()][i]+i;
	k = i;
      }
    }
    string path;
    for (int i = 0; i < k; i++) path += ')';
    int starts = 0;
    while (a || b) {
      Par&p = par[a][b][k];
      path += p.c;
      if (k == 0 && p.k == 0) starts++;
      tie(a,b,k) = make_tuple(p.a,p.b,p.k);
    }
    for (int i = 0; i < starts; i++) path += '(';
    reverse(path.begin(), path.end());
    cout << path << endl;
  }
}