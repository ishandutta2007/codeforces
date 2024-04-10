#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5010;
vector<int> node[nax];

int done[nax];

void dfs(array<vector<int>, 2>&cc, int p, int col = 1) {
  if (done[p]) {
    if (done[p] != col) {
      cout << "NO" << endl;
      exit(0);
    }
    return;
  }
  done[p] = col;
  cc[col-1].push_back(p);
  for (int i : node[p]) dfs(cc, i, 3-col);
}

int par[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, edges;
  cin >> n >> edges;
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  assert(n1+n2+n3 == n);
  while (edges--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  vector<array<vector<int>, 2>> cc;
  for (int i = 0; i < n; i++) {
    if (done[i]) continue;
    cc.push_back({});
    dfs(cc.back(), i);
  }

  int m = cc.size();
  fill_n((int*)par, nax*nax, -1);
  par[0][0] = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < nax; j++) {
      if (par[i][j] != -1) {
	for (int k : {0,1})
	  par[i+1][j+(int)cc[i][k].size()] = k;
      }
    }
  }

  if (par[m][n2] == -1) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> evens, odds;
  {
    int j = n2;
    for (int i = m; i; i--) {
      int k = par[i][j];
      assert(k != -1);
      for (int x : cc[i-1][k])
	evens.push_back(x);
      for (int x : cc[i-1][!k])
	odds.push_back(x);
      j -= (int)cc[i-1][k].size();
    }
    assert(!j);
    assert((int)evens.size() == n2);
  }
  string ans(n,'2');
  for (int i = 0; i < n1; i++)
    ans[odds[i]] = '1';
  for (int i = n1; i < n1+n3; i++)
    ans[odds[i]] = '3';
  cout << "YES" << endl;
  cout << ans << endl;
}