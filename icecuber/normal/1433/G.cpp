#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e3;
vector<array<int,2>> node[nax];
int cost[nax][nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;

  vector<array<int,2>> edge;
  fill_n((int*)cost, nax*nax, 1e9);
  for (int i = 0; i < n; i++) cost[i][i] = 0;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edge.push_back({a, b});
    node[a].push_back({b, c});
    node[b].push_back({a, c});
    cost[a][b] = min(cost[a][b], c);
    cost[b][a] = min(cost[b][a], c);
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      assert(cost[i][j] < 1e9);

  vector<array<int,2>> route(q);
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    route.push_back({a,b});
  }

  int ans = 1e9;
  for (auto [u,v] : edge) {
    int total = 0;
    for (auto [a,b] : route) {
      total += min({cost[a][b], cost[a][u]+cost[v][b], cost[a][v]+cost[u][b]});
    }
    ans = min(ans, total);
  }
  cout << ans << endl;
}