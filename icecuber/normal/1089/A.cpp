#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Entry {
  int val;
  int pa, pb;
};
Entry dp[4][4][201][201];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  dp[0][0][0][0] = {1,0,0};
  for (int sa = 0; sa < 4; sa++) {
    for (int sb = 0; sb < 4; sb++) {
      for (int pa = 0; pa <= 200; pa++) {
	for (int pb = 0; pb <= 200; pb++) {
	  if (!dp[sa][sb][pa][pb].val) continue;
	  if (sa+sb >= 5 || max(sa,sb) >= 3) continue;
	  int ma = sa+sb == 4 ? 15 : 25;
	  //A wins clearly
	  for (int i = 0; i < ma-1; i++) {
	    int nsa = sa+1, nsb = sb, npa = pa+ma, npb = pb+i;
	    if (nsa <= 3 && nsb <= 3 && npa <= 200 && npb <= 200)
	      dp[nsa][nsb][npa][npb] = {1,ma,i};
	  }
	  //B wins clearly
	  for (int i = 0; i < ma-1; i++) {
	    int nsa = sa, nsb = sb+1, npa = pa+i, npb = pb+ma;
	    if (nsa <= 3 && nsb <= 3 && npa <= 200 && npb <= 200)
	      dp[nsa][nsb][npa][npb] = {1,i,ma};
	  }
	  //A wins in tie break
	  for (int i = ma+1; pa+i <= 200 && pb+i-2 <= 200; i++) {
	    int nsa = sa+1, nsb = sb, npa = pa+i, npb = pb+i-2;
	    if (nsa <= 3 && nsb <= 3 && npa <= 200 && npb <= 200)
	      dp[nsa][nsb][npa][npb] = {1,i,i-2};
	  }
	  //B wins in tie break
	  for (int i = ma+1; pa+i-2 <= 200 && pb+i <= 200; i++) {
	    int nsa = sa, nsb = sb+1, npa = pa+i-2, npb = pb+i;
	    if (nsa <= 3 && nsb <= 3 && npa <= 200 && npb <= 200)
	      dp[nsa][nsb][npa][npb] = {1,i-2,i};
	  }
	}
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    for (int d = 3; d >= -3; d--) {
      for (int sa = 0; sa < 4; sa++)
	for (int sb = 0; sb < 4; sb++)
	  if (sa-sb == d && (max(sa,sb) == 3) && dp[sa][sb][a][b].val) {
	    cout << sa << ':' << sb << endl;
	    vector<pair<int,int>> path;
	    while (a||b) {
	      int pa = dp[sa][sb][a][b].pa;
	      int pb = dp[sa][sb][a][b].pb;
	      path.push_back({pa,pb});
	      sa -= pa>pb;
	      sb -= pb>pa;
	      a -= pa;
	      b -= pb;
	    }
	    reverse(path.begin(), path.end());
	    for (auto p : path)
	      cout << p.first << ':' << p.second << ' ';
	    cout << endl;
	    goto done;
	  }
    }
    cout << "Impossible" << endl;
    done:;
  }
}