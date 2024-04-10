#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> val[4][4];

int done[4];
int deg[2];
ll sumval;
void dfs(int p) {
  if (done[p]++) return;
  int outs = 0;
  for (int i = 0; i < 4; i++) {
    if (val[max(p,i)][min(p,i)].size()) {
      dfs(i);
      outs += (i != p)*val[max(p,i)][min(p,i)].size();
      if (i <= p)
	for (int v : val[max(p,i)][min(p,i)])
	  sumval += v;
    }
  }
  deg[outs%2]++;
}

ll solve() {
  ll ans = 0;
  for (int i = 0; i < 4; i++) {
    sumval = 0;
    fill_n(done, 4, 0);
    fill_n(deg, 4, 0);
    dfs(i);
    if (deg[1] == 0 || deg[1] == 2) {
      ans = max(ans, sumval);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> c >> b;
    a--, b--;
    if (a < b) swap(a,b);
    val[a][b].push_back(c);
  }
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b <= a; b++) {
      sort(val[a][b].rbegin(), val[a][b].rend());
    }
  }
  ll ans = solve();
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b <= a; b++) {
      if (val[a][b].size()) {
	int backup = val[a][b].back();
	val[a][b].pop_back();
	ans = max(ans, solve());
	val[a][b].push_back(backup);
      }
    }
  }
  cout << ans << endl;
}