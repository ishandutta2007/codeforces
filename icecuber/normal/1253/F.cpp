#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+123;
vector<pair<int,ll>> core[nax];
void addEdge(int a, int b, ll c) {
  core[a].push_back({b,c});
  core[b].push_back({a,c});
}
int done[nax];
int par[20][nax];
ll ma[20][nax];
int depth[nax];

vector<pair<int,ll>> node[nax];
ll dist[nax];
int base[nax];


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    node[a].push_back({b,c});
    node[b].push_back({a,c});
  }

  {
    priority_queue<pair<ll,int>> pq;
    fill_n(dist, n, 1e18);
    fill_n(base, n, -1);
    for (int i = 0; i < k; i++) {
      dist[i] = 0;
      base[i] = i;
      pq.push({0,i});
    }
    while (pq.size()) {
      int p = pq.top().second;
      ll d = -pq.top().first;
      pq.pop();
      if (d > dist[p]) {
	continue;
      }
      for (auto e : node[p]) {
	int j = e.first;
	ll w = e.second;
	if (base[j] != -1 && base[j] != base[p]) {
	  assert(base[p] != -1);
	  addEdge(base[j], base[p], dist[j]+dist[p]+w);
	}
	if (dist[p]+w < dist[j]) {
	  dist[j] = dist[p]+w;
	  base[j] = base[p];
	  pq.push({-dist[j], j});
	}
      }
    }
  }

  {
    priority_queue<tuple<ll,int,int>> pq;
    pq.push({0,0,k});
    depth[k] = -1;
    par[0][k] = k;
    while (pq.size()) {
      int p, pa;
      ll w;
      tie(w,p,pa) = pq.top();
      w *= -1;
      pq.pop();
      if (done[p]++) continue;
      par[0][p] = pa;
      depth[p] = depth[pa]+1;
      ma[0][p] = w;
      for (auto e : core[p]) {
	int j = e.first;
	ll w = e.second;
	pq.push({-w,j,p});
      }
    }
  }

  /*for (int i = 0; i <= k; i++) {
    cout << depth[i] << ' ';
  }
  cout << endl;
  return 0;*/

  for (int l = 0; l+1 < 20; l++) {
    for (int i = 0; i <= k; i++) {
      int p = par[l][i];
      par[l+1][i] = par[l][p];
      ma[l+1][i] = max(ma[l][p], ma[l][i]);
    }
  }
  for (int i = 0; i <= k; i++) {
    assert(par[19][i] == k);
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (depth[b] > depth[a]) swap(a,b);
    ll ans = 0;
    for (int l = 19; l >= 0; l--) {
      if (depth[a]-(1<<l) >= depth[b]) {
	ans = max(ans, ma[l][a]);
	int d0 = depth[a];
	a = par[l][a];
	assert(depth[a] == d0-(1<<l));
      }
    }
    assert(depth[a] == depth[b]);
    for (int l = 19; l >= 0; l--) {
      if (par[l][a] != par[l][b]) {
	ans = max(ans, ma[l][a]);
	a = par[l][a];
	ans = max(ans, ma[l][b]);
	b = par[l][b];
      }
    }
    if (a != b) {
      int l = 0;
      ans = max(ans, ma[l][a]);
      a = par[l][a];
      ans = max(ans, ma[l][b]);
      b = par[l][b];
    }
    assert(a < k && b < k);
    assert(a == b);
    cout << ans << '\n';
  }
}