#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];

int sz[nax];
void dfs(int p, int par) {
  sz[p] = 1;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    sz[p] += sz[i];
  }
}

ll totmove = 0;
vector<int> vlist;
void reclist(int p, int par, int d) {
  totmove += d;
  vlist.push_back(p);
  for (int i : node[p]) {
    if (i == par) continue;
    reclist(i, p, d+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0, -1);

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int centroid = 1;
    for (int j : node[i]) {
      int s = (sz[j] > sz[i] ? n-sz[i] : sz[j]);
      if (s*2 > n) centroid = 0;
    }
    if (centroid) {
      vlist.push_back(i);
      for (int j : node[i])
	reclist(j, i, 1);
      for (int j = 0; j < n; j++)
	ans[vlist[j]] = vlist[(j+n/2)%n];
      break;
    }
  }

  cout << totmove*2 << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i]+1 << ' ';
  cout << endl;
}