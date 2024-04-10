#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dist[10010][1010];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> safe(m);
  for (int&p : safe) cin >> p;
  sort(safe.begin(), safe.end());
  ll g, r;
  cin >> g >> r;
  fill_n((ll*)dist, 10010*1010, 1e18);
  dist[0][0] = 0;
  deque<tuple<ll,int,int>> pq;
  pq.emplace_back(0, 0, 0);
  ll cc = 0;
  while (pq.size()) {
    auto [d, p, t] = pq.front();
    pq.pop_front();
    if (dist[p][t] < d) continue;
    for (int np : {p-1,p+1}) {
      if (np >= 0 && np < m) {
	int md = abs(safe[np]-safe[p]);
	if (md <= g-t) {
	  ll nd = d+(md==g-t);
	  int nt = (t+md)%g;
	  if (nd < dist[np][nt]) {
	    cc++;
	    dist[np][nt] = nd;
	    if (nd == d)
	      pq.emplace_front(nd, np, nt);
	    else
	      pq.emplace_back(nd, np, nt);
	  }
	}
      }
    }
  }
  //cout << cc << endl;
  ll ans = 1e18;
  for (int t = 0; t < g; t++) {
    if (dist[m-1][t] < 1e17) {
      ll cost = dist[m-1][t]*(g+r)+t;
      if (t == 0 && dist[m-1][t]) cost -= r;
      ans = min(ans, cost);
    }
  }
  if (ans == 1e18) ans = -1;
  cout << ans << endl;
}