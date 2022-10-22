#include <bits/stdc++.h>
using namespace std;

const int nax = 3e5;
vector<int> node[nax];
int dist[nax], par[nax];

int main() {
  int n, m;
  cin >> n >> m;

  set<pair<int,int>> edges;
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges.insert({a,b});
    edges.insert({b,a});
    node[a].push_back(b);
    node[b].push_back(a);
  }

  fill_n(dist, n, 1e9);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p]) {
      if (dist[i] == 1e9) {
	dist[i] = dist[p]+1;
	par[i] = p;
	q.push(i);
      }
    }
  }

  if (dist[n-1] <= 4) {
    vector<int> path;
    for (int p = n-1; p; p = par[p]) {
      path.push_back(p);
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    cout << dist[n-1] << endl;
    for (int p : path) cout << p+1 << ' ';
    cout << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (dist[i] == 2) {
      cout << 4 << endl;
      cout << 1 << ' ' << par[i]+1 << ' ' << i+1 << ' ' << 1 << ' ' << n << endl;
      return 0;
    }
  }

  fill_n(dist, n, 1e9);
  dist[0] = -1;
  for (int i : node[0]) {
    if (dist[i] != 1e9) continue;
    vector<int> list = {i};
    dist[i] = 0;
    int s = 0;
    while (s < list.size()) {
      int p = list[s++];
      for (int j : node[p]) {
	if (dist[j] == 1e9) {
	  dist[j] = 0;
	  list.push_back(j);
	}
      }
    }
    for (int i : list) {
      for (int j : list) {
	if (i != j && !edges.count({i,j})) {
	  for (int a : node[i]) {
	    if (!a) continue;
	    for (int b : node[a]) {
	      if (!a || i == b || edges.count({i,b})) continue;
	      cout << 5 << endl;
	      cout << 1 << ' ' << i+1 << ' ' << a+1 << ' ' << b+1 << ' ' << i+1 << ' ' << n << endl;
	      return 0;
	    }
	  }
	  assert(0);
	}
      }
    }
  }
  cout << -1 << endl;
}