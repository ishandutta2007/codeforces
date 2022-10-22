#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[2][nax];

int cdone[nax];
vector<int> topo;
void cycle(int p) {
  if (cdone[p]++) return;
  for (int i : node[0][p]) cycle(i);
  topo.push_back(p);
}

int done[2][nax];
void dfs(int p, int k) {
  if (done[k][p]++) return;
  for (int i : node[k][p]) dfs(i,k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[0][a].push_back(b);
    node[1][b].push_back(a);
  }
  for (int i = 0; i < n; i++) cycle(i);
  fill_n(cdone, n, 0);
  for (int i : topo) {
    for (int j : node[1][i])
      if (cdone[j]) {
	cout << -1 << endl;
	exit(0);
      }
    cdone[i] = 1;
  }

  string ans;
  for (int i = 0; i < n; i++) {
    if (done[0][i] || done[1][i])
      ans += 'E';
    else {
      ans += 'A';
    }
    dfs(i, 0);
    dfs(i, 1);
  }
  cout << count(ans.begin(), ans.end(), 'A') << endl;
  cout << ans << endl;
}