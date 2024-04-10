#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> conn[64];

set<int> node[100000];

int dist[100000];
int bfs(int a, int b) {
  fill_n(dist, 100000, 1e9);
  queue<int> q;
  q.push(a);
  dist[a] = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    int dd = dist[p]+1;
    for (int i : node[p]) {
      if (dd < dist[i]) {
	dist[i] = dd;
	q.push(i);
      }
    }
  }
  return dist[b];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 64; j++) {
      if (a[i]>>j&1) {
	conn[j].push_back(i);
      }
    }
  }
  for (int j = 0; j < 64; j++) {
    if (conn[j].size() >= 3) {
      cout << 3 << endl;
      return 0;
    }
  }

  vector<pair<int,int>> edges;
  for (int j = 0; j < 64; j++) {
    if (conn[j].size() == 2) {
      int a = conn[j][0];
      int b = conn[j][1];
      edges.push_back({a,b});
      node[a].insert(b);
      node[b].insert(a);
    }
  }

  int ans = 1e9;
  for (auto p : edges) {
    int a = p.first, b = p.second;
    node[b].erase(a);
    node[a].erase(b);
    int len = bfs(a, b)+1;
    node[a].insert(b);
    node[b].insert(a);
    if (len >= 3) {
      ans = min(ans, len);
    }
  }
  if (ans == 1e9) cout << -1 << endl;
  else cout << ans << endl;
}