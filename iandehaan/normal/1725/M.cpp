#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

ll inf = ((ll) 1) << ((ll) 50);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	vector<pair<int, ll>> adj[n];
	vector<pair<int, ll>> radj[n];
	rep(i, 0, m) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; v--;
		adj[u].pb(mp(v, w));
		radj[v].pb(mp(u, w));
	}

	ll dist[n];
	rep(i, 0, n) dist[i] = inf;
	dist[0] = 0;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	q.push(mp(0, 0));
	while (!q.empty()) {
		pair<ll, int> top = q.top(); q.pop();
		if (top.first > dist[top.second]) continue;

		for (pair<int, ll> nxt : adj[top.second]) {
			ll nxtdist = nxt.second + top.first;
			if (nxtdist < dist[nxt.first]) {
				dist[nxt.first] = nxtdist;
				q.push(mp(nxtdist, nxt.first));
			}
		}
	}

	rep(i, 0, n) if (dist[i] < inf) q.push(mp(dist[i], i));
	while (!q.empty()) {
		pair<ll, int> top = q.top(); q.pop();
		if (top.first > dist[top.second]) continue;

		for (pair<int, ll> nxt : radj[top.second]) {
			ll nxtdist = nxt.second + top.first;
			if (nxtdist < dist[nxt.first]) {
				dist[nxt.first] = nxtdist;
				q.push(mp(nxtdist, nxt.first));
			}
		}
	}

	rep(i, 1, n) {
		if (dist[i] == inf) cout << -1 << ' ';
		else cout << dist[i] << ' ';
	}
	cout << endl;
}