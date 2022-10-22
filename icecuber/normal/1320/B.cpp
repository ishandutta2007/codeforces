#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax], rnode[nax];
int dist[nax], ways[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    rnode[b].push_back(a);
  }

  fill_n(dist, n, 1e9);
  int k;
  cin >> k;
  vector<int> path(k);
  for (int&v : path) {
    cin >> v;
    v--;
  }
  queue<int> q;
  q.push(path.back());
  dist[path.back()] = 0;
  ways[path.back()] = 1;

  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : rnode[p]) {
      if (dist[i] == 1e9) {
	dist[i] = dist[p]+1;
	q.push(i);
      }
      if (dist[i] == dist[p]+1)
	ways[i] = min(ways[i]+ways[p], 2);
    }
  }

  int mi = 0, ma = 0;
  for (int i = 0; i+1 < k; i++) {
    if (dist[path[i]]-dist[path[i+1]] != 1) mi++;
    int other = 0;
    for (int j : node[path[i]]) {
      if (dist[j] == dist[path[i]]-1 && j != path[i+1]) other = 1;
    }
    ma += other;
  }
  cout << mi << ' ' << ma << endl;
}