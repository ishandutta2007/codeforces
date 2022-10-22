#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int deg[1000000], deg0[1000000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
    deg0[a]++, deg0[b]++;
    edges.emplace_back(a,b);
  }
  random_shuffle(edges.begin(), edges.end());
  vector<pair<int,int>> ans;
  for (auto e : edges) {
    int a = e.first, b = e.second;
    if (deg[a]-1 >= (deg0[a]+1)/2 &&
	deg[b]-1 >= (deg0[b]+1)/2) {
      deg[a]--, deg[b]--;
    } else {
      ans.emplace_back(a,b);
    }
  }
  cout << ans.size() << endl;
  for (auto e : ans)
    cout << e.first+1 << ' ' << e.second+1 << endl;
}