#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct edge {
	int from, to;
	ll cost;
};

vector<int> tin, tout;
int timer = 0;
vector<edge> edges;
vector<int> euler;
vector<vector<int> > g;

void dfs(int v) {
	tin[v] = timer++;
	euler.pb(v);
	for (int e : g[v]) {
		dfs(edges[e].to);
	}
	euler.pb(v);
	tout[v] = timer++;
}

bool ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

struct node {
	ll promise;
	ll minn;
	node() : promise(0), minn(0) {}
};

vector<node> t;

void push(int v) {
	ll val = t[v].promise;
	t[v].promise = 0;
	t[v * 2].promise += val;
	t[v * 2].minn += val;
	t[v * 2 + 1].promise += val;
	t[v * 2 + 1].minn += val;
}

void update(int v, int tl, int tr, int l, int r, ll val) {
	if (tl == l && tr == r) {
		t[v].promise += val;
		t[v].minn += val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		update(v * 2, tl, tm, l, min(r, tm), val);
	}
	if (r > tm) {
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
	}
	t[v].minn = min(t[v * 2].minn, t[v * 2 + 1].minn);
}

ll get(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v].minn;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	ll ans = ll(1e18);
	if (l <= tm) {
		ans = min(ans, get(v * 2, tl, tm, l, min(r, tm)));
	}
	if (r > tm) {
		ans = min(ans, get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	int n, q;
	cin >> n >> q;

	g.resize(n);
	tin.resize(n);
	tout.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll cost;
		cin >> u >> v >> cost;
		--u, --v;
		g[u].pb(sz(edges));
		edges.pb({u, v, cost});
	}

	vector<ll> toRoot(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll cost;
		cin >> u >> v >> cost;
		--u, --v;
		toRoot[u] = cost;
		edges.pb({u, v, cost});
	}

	dfs(0);

	int N = sz(euler);
	t.resize(4 * N);

	for (int i = 0; i < n - 1; ++i) {
		int v = edges[i].to;
		update(1, 0, N - 1, tin[v], tout[v], edges[i].cost);
	}
	for (int i = 1; i < n; ++i) {
		update(1, 0, N - 1, tin[i], tin[i], toRoot[i]);
		update(1, 0, N - 1, tout[i], tout[i], toRoot[i]);
	}

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int id;
			ll cost;
			cin >> id >> cost;
			--id;
			if (edges[id].to == 0) {
				ll delta = cost - toRoot[edges[id].from];
				update(1, 0, N - 1, tin[edges[id].from], tin[edges[id].from], delta);
				update(1, 0, N - 1, tout[edges[id].from], tout[edges[id].from], delta);
				toRoot[edges[id].from] = cost;
				continue;
			}
			ll delta = cost - edges[id].cost;
			edges[id].cost = cost;
			update(1, 0, N - 1, tin[edges[id].to], tout[edges[id].to], delta);
		} else {
			int u, v;
			cin >> u >> v;
			--u, --v;
			if (ancestor(u, v)) {
				ll ans = get(1, 0, N - 1, tin[v], tin[v]) - toRoot[v];
				ans -= (get(1, 0, N - 1, tin[u], tin[u]) - toRoot[u]);
				cout << ans << "\n";
			} else {
				ll ans = get(1, 0, N - 1, tin[u], tout[u]) - (get(1, 0, N - 1, tin[u], tin[u]) - toRoot[u]);
				ans += get(1, 0, N - 1, tin[v], tin[v]) - toRoot[v];
				cout << ans << "\n";
			}
		}
	}

}