#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct edge {
	int from, to;
	ll cost;
	int id;
};

const ll inf = 1e18;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<edge> > g(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		--u, --v;
		g[u].pb({u, v, c, i});
		g[v].pb({v, u, c, i});
	}

	vector<ll> dist(n, inf);
	dist[0] = 0;
	auto comp = [&] (int a, int b) {
		if (dist[a] != dist[b]) {
			return dist[a] < dist[b];
		}
		return a < b;
	};

	set<int, decltype(comp)> q(comp);
	q.insert(0);

	vector<int> pr(n);
	while (!q.empty()) {
		int v = *q.begin();
		q.erase(q.begin());
		for (edge& e : g[v]) {
			if (e.cost + dist[v] < dist[e.to]) {
				q.erase(e.to);
				dist[e.to] = dist[v] + e.cost;
				pr[e.to] = e.id;
				q.insert(e.to);
			}
		}
	}

	vector<int> vct;
	for (int i = 1; i < n; ++i) {
		vct.pb(i);
	}
	sort(all(vct), comp);
	cout << k << endl;

	set<int> alive;
	for (int i = 0; i < m; ++i) {
		alive.insert(i);
	}

	for (int i = 1; i < n && k; ++i) {
		int v = vct[i - 1];
		--k;
		cout << pr[v] + 1 << " ";
		alive.erase(pr[v]);
	}

	while (k--) {
		cout << *alive.begin() + 1 << " ";
		alive.erase(alive.begin());
	}

}