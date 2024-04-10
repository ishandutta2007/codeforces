#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cap[3000][3000];
vector<int> node[3000];
int done[3000];

ll maxflow(int p, int sink, ll flow = 1e18) {
  if (p == sink) return flow;
  done[p] = 1;
  for (int i : node[p]) {
    ll flow2;
    if (cap[p][i] && !done[i]++ && (flow2 = maxflow(i, sink, min(flow, cap[p][i])))) {
      cap[p][i] -= flow2;
      cap[i][p] += flow2;
      return flow2;
    }
  }
  return 0;
}

int par[3000];
ll maxflow2(int source, int sink) {
  queue<int> q;
  q.push(source);
  while (q.size()) {
    int p = q.front();
    q.pop();
    for (int i : node[p]) {
      if (cap[p][i] && !done[i]++) {
	par[i] = p;
	q.push(i);
      }
    }
  }
  if (!done[sink]) return 0;
  ll flow = 1e18;
  for (int p = sink; p != source; p = par[p])
    flow = min(flow, cap[par[p]][p]);
  for (int p = sink; p != source; p = par[p]) {
    cap[par[p]][p] -= flow;
    cap[p][par[p]] += flow;
  }
  return flow;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll ans = 0, source = n+m, sink = n+m+1, k = n+m+2;
  for (int i = 0; i < n; i++) {
    cin >> cap[source][i];
    node[source].push_back(i);
    node[i].push_back(source);
  }
  for (int j = 0; j < m; j++) {
    ll a, b, w;
    cin >> a >> b >> w;
    a--,b--;
    ans += w;
    cap[n+j][sink] = w;
    cap[a][n+j] = 1e18;
    cap[b][n+j] = 1e18;
    node[n+j].push_back(sink);
    node[a].push_back(n+j);
    node[b].push_back(n+j);
    node[sink].push_back(n+j);
    node[n+j].push_back(a);
    node[n+j].push_back(b);
  }

  /*for (int i = 0; i < k; i++)
    for (int j : node[i])
      cout << i << ' ' << j << ' ' << cap[i][j] << endl;
      cout << endl;*/

  while (1) {
    fill_n(done, k, 0);
    ll flow = maxflow(source, sink);
    //cout << flow << endl;
    if (!flow) break;
    ans -= flow;
  }
  cout << ans << endl;
}