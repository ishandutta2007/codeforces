#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a0[500], b0[500];
int a[500], b[500];
int dp[500][500];
int nexta[500][1000];
int nextb[500][1000];
int lasta[1000], lastb[1000];
int para[500][500], parb[500][500];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int,int> ma;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a0[i];
    ma[a0[i]];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> b0[i];
    ma[b0[i]];
  }
  int c = 0;
  for (auto&p : ma) p.second = c++;

  fill_n(lasta, c, n);
  for (int i = n-1; i >= 0; i--) {
    a[i] = ma[a0[i]];
    for (int j = 0; j < c; j++)
      nexta[i][j] = lasta[j];
    lasta[a[i]] = i;
  }
  fill_n(lastb, c, m);
  for (int i = m-1; i >= 0; i--) {
    b[i] = ma[b0[i]];
    for (int j = 0; j < c; j++)
      nextb[i][j] = lastb[j];
    lastb[b[i]] = i;
  }

  int ans = 0;
  int besti = -1, bestj = -1;
  //dp[i][j] = LCIS ending at (i,j)
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] != b[j]) continue;
      if (dp[i][j] < 1) {
	dp[i][j] = 1;
	para[i][j] = -1;
	parb[i][j] = -1;
      }
      if (dp[i][j] > ans) {
	ans = dp[i][j];
	besti = i;
	bestj = j;
      }
      int v = dp[i][j]+1;
      for (int k = a[i]+1; k < c; k++) {
	int na = nexta[i][k];
	int nb = nextb[j][k];
	if (na < n && nb < m && v > dp[na][nb]) {
	  assert(a[na] == b[nb]);
	  dp[na][nb] = v;
	  para[na][nb] = i;
	  parb[na][nb] = j;
	}
      }
    }
  }
  cout << ans << endl;
  int i = besti, j = bestj;
  vector<int> path;
  while (i > -1 && j > -1) {
    path.push_back(a0[i]);
    int ni = para[i][j];
    int nj = parb[i][j];
    i = ni, j = nj;
  }
  reverse(path.begin(), path.end());
  for (int v : path) cout << v << ' ';
  cout << endl;
}