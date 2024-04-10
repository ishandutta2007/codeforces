#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];
int depth[nax];
int k;

vector<int> indep[2];

void dfs(int p, int par, int d) {
  static vector<int> path;
  if (depth[p]) {
    if (d > depth[p] && d-depth[p] <= k) {
      cout << 2 << endl;
      cout << d-depth[p] << endl;
      for (int i = depth[p]; i < d; i++) {
	cout << path[i-1]+1 << ' ';
      }
      cout << endl;
      exit(0);
    }
    return;
  }
  if (d <= k)
    indep[d%2].push_back(p);
  path.push_back(p);
  depth[p] = d;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p, d+1);
  }
  path.pop_back();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m >> k;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0, -1, 1);

  cout << 1 << endl;
  int ma = (indep[1].size() > indep[0].size());
  for (int i = 0; i < (k+1)/2; i++)
    cout << indep[ma][i]+1 << ' ';
  cout << endl;
}