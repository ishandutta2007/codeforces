#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
  int a, b, c, i;
};

const int nax = 1e5;
vector<Edge> node[nax], rnode[nax];
vector<ll> sdist(nax), tdist(nax);

vector<Edge> DAG[nax];

void dijkstra(vector<Edge> node[], int start, vector<ll>&dist) {
  priority_queue<pair<ll,int>> pq;
  pq.push({0, start});
  fill_n(dist.begin(), nax, 1e16);
  dist[start] = 0;
  while (pq.size()) {
    auto [d, p] = pq.top();
    pq.pop();
    d *= -1;
    if (d > dist[p]) continue;
    for (Edge e : node[p]) {
      if (d + e.c < dist[e.b]) {
	dist[e.b] = d + e.c;
	pq.push({-dist[e.b], e.b});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  s--, t--;
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edges.push_back({a, b, c, i});
    node[a].push_back({a, b, c, i});
    rnode[b].push_back({b, a, c, i});
  }
  dijkstra(node, s, sdist);
  dijkstra(rnode, t, tdist);

  vector<pair<ll,int>> order;
  for (int i = 0; i < n; i++) {
    for (Edge e : node[i]) {
      if (sdist[i] + e.c + tdist[e.b] == sdist[t]) {
	DAG[i].push_back(e);
      }
    }
    order.emplace_back(sdist[i], i);
  }
  sort(order.begin(), order.end());
  vector<int> inv(n);
  for (int i = 0; i < n; i++) inv[order[i].second] = i;

  vector<int> acc_xor(n+1), acc_cnt(n+1);
  for (auto [d, p] : order) {
    for (Edge e : DAG[p]) {
      int ia = inv[e.a], ib = inv[e.b];
      acc_xor[ia] ^= e.i;
      acc_xor[ib] ^= e.i;
      acc_cnt[ia]++;
      acc_cnt[ib]--;
    }
  }
  vector<int> needed(m);
  for (int i = 0; i < n; i++) {
    if (acc_cnt[i] == 1) {
      needed[acc_xor[i]] = 1;
    }
    acc_xor[i+1] ^= acc_xor[i];
    acc_cnt[i+1] += acc_cnt[i];
  }
  for (Edge e : edges) {
    if (needed[e.i]) {
      cout << "YES" << '\n';
    } else {
      ll nc = sdist[t] - (sdist[e.a] + tdist[e.b]) - 1;
      if (nc <= 0) cout << "NO" << '\n';
      else cout << "CAN " << e.c-nc << '\n';
    }
  }
}