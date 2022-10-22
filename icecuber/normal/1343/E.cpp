#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
ll distA[nax], distB[nax], distC[nax];

void bfs(int start, ll*dist, int n) {
  fill_n(dist, n, 1e9);
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
  int t;
  cin >> t;
  while (t--) {
    int n, m, A, B, C;
    cin >> n >> m >> A >> B >> C;
    A--, B--, C--;
    for (int i = 0; i < n; i++) node[i].clear();

    vector<ll> prices(m);
    for (ll&v : prices) cin >> v;
    sort(prices.begin(), prices.end());

    vector<ll> acc = {0};
    for (int i = 0; i < m; i++) {
      acc.push_back(acc.back()+prices[i]);
    }

    for (int it = 0; it < m; it++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    bfs(A, distA, n);
    bfs(B, distB, n);
    bfs(C, distC, n);
    ll ans = 1e18;
    for (int x = 0; x < n; x++) {
      ll sum = distA[x]+distB[x]+distC[x];
      if (sum > m) continue;
      ans = min(ans, acc[sum]+acc[distB[x]]);
    }
    cout << ans << endl;
  }
}