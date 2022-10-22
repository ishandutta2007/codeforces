#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> node(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }

    vector<int> sz(n);
    function<void(int,int)> dfs1 = [&](int p, int par) {
      sz[p] = 1;
      for (int i : node[p]) {
	if (i == par) continue;
	dfs1(i,p);
	sz[p] += sz[i];
      }
    };
    dfs1(0, -1);

    function<pair<int,int>(int,int)> dfs2 = [&](int p, int par) {
      for (int i : node[p]) {
	if (i == par) continue;
	return dfs2(i,p);
      }
      return make_pair(p, par);
    };

    for (int i = 0; i < n; i++) {
      pair<int,int> ma = {0,-1};
      for (int j : node[i]) {
	if (sz[j] > sz[i]) ma = max(ma, make_pair(n-sz[i], j));
	else ma = max(ma, make_pair(sz[j], j));
      }
      if (ma.first <= n/2) {
	auto [a,b] = dfs2(ma.second, i);
	cout << a+1 << ' ' << b+1 << endl;
	cout << a+1 << ' ' << i+1 << endl;
	break;
      }
    }
  }
}