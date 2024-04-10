#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, a0, b0, da, db;
    cin >> n >> a0 >> b0 >> da >> db;
    a0--, b0--;

    vector<vector<int>> node(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }

    array<int,2> furthest = {-1,-1};
    vector<int> dist(n, -1);
    function<void(int, int)> dfs = [&](int p, int d) {
      if (dist[p] != -1) return;
      dist[p] = d;
      furthest = max(furthest, array<int,2>{d,p});
      for (int i : node[p]) {
	dfs(i, d+1);
      }
    };
    dfs(a0, 0);
    int d0 = dist[b0];
    int start2 = furthest[1];
    furthest = {-1,-1};
    fill_n(dist.begin(), n, -1);
    dfs(start2, 0);
    int diam = furthest[0];
    cout << (diam > 2*da && db > 2*da && d0 > da ? "Bob" : "Alice") << endl;
  }
}