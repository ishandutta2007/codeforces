#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];

void bfs(int start, vector<int>&dist) {
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p]) {
      if (dist[i] == 1e9) {
	dist[i] = dist[p]+1;
	q.push(i);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> special(k);
  for (int&v : special) {
    cin >> v;
    v--;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  vector<int> ds(n,1e9),de(n,1e9);
  bfs(0, ds);
  bfs(n-1, de);
  vector<pair<int,int>> p;
  for (int i : special) {
    p.emplace_back(ds[i], de[i]);
  }
  sort(p.begin(), p.end());
  int ans = 0;
  map<int,int> pareto;
  for (auto [x,y] : p) {
    int pass = 0, fail = ds[n-1];
    while (fail-pass > 1) {
      int mid = pass+fail>>1;
      auto it = pareto.lower_bound(mid-y);
      if (it != pareto.end() && it->second >= mid-x)
	pass = mid;
      else
	fail = mid;
    }
    while (pareto.size() && pareto.rbegin()->second <= y) pareto.erase(pareto.rbegin()->first);
    pareto[x] = y;
    ans = max(ans, pass+1);
  }
  cout << min(ans, ds[n-1]) << endl;
}