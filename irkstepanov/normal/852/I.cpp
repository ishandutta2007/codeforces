#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int rmax = 18;

vector<vector<int> > g;
vector<int> tin, tout;
vector<vector<int> > parent;
vector<int> euler;
vector<int> tp, val;
int timer = 0;

void dfs(int v, int p) {
	tin[v] = timer++;
	euler.pb(v);
	parent[v][0] = p;
	for (int r = 0; r + 1 < rmax; ++r) {
		int t = parent[v][r];
		parent[v][r + 1] = parent[t][r];
	}
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v);
	}
	tout[v] = timer++;
	euler.pb(v);
}

bool ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (ancestor(u, v)) {
		return u;
	}
	for (int r = rmax - 1; r >= 0; --r) {
		if (!ancestor(parent[u][r], v)) {
			u = parent[u][r];
		}
	}
	return parent[u][0];
}

const int buben = 316;

struct query {
	int lf;
	int rg;
	int lca;
	int id;
	bool operator<(const query& other) {
		if (lf / buben != other.lf / buben) {
			return lf / buben < other.lf / buben;
		}
		return rg < other.rg;
	}
};

vector<ll> ans;
vector<int> cnt[2];
vector<char> active;
ll sum = 0;

void change(int v) {
	//cout << "CHANGE " << v + 1 << endl;
	int x = val[v];
	if (active[v]) {
		sum -= cnt[1 - tp[v]][x];
		--cnt[tp[v]][x];
		active[v] = false;
	} else {
		sum += cnt[1 - tp[v]][x];
		++cnt[tp[v]][x];
		active[v] = true;
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;
	tp.resize(n), val.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> tp[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> val[i];
	}
	vector<int> sorted = val;
	sort(all(sorted));
	sorted.resize(unique(all(sorted)) - sorted.begin());
	for (int i = 0; i < n; ++i) {
		val[i] = lower_bound(all(sorted), val[i]) - sorted.begin();
	}

	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	parent = vector<vector<int> >(n, vector<int>(rmax));
	dfs(0, 0);

	int q;
	cin >> q;
	vector<query> queries(q);
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (tin[u] > tin[v]) {
			swap(u, v);
		}
		int w = lca(u, v);
		if (w == u || w == v) {
			assert(w == u);
			queries[i] = {tin[u], tin[v], -1, i};
		} else {
			queries[i] = {tout[u], tin[v], w, i};
		}
	}
	sort(all(queries));

	active.assign(n, false);
	ans.resize(q);
	for (int i = 0; i < 2; ++i) {
		cnt[i].resize(sz(sorted));
	}

	/*for (int v : euler) {
		cout << v + 1 << " ";
	}
	cout << "\n";*/

	int l = queries[0].lf, r = queries[0].lf - 1;
	for (int i = 0; i < q; ++i) {
		while (l < queries[i].lf) {
			change(euler[l]);
			++l;
		}
		while (l > queries[i].lf) {
			change(euler[l - 1]);
			--l;
		}

		while (r < queries[i].rg) {
			change(euler[r + 1]);
			++r;
		}
		while (r > queries[i].rg) {
			change(euler[r]);
			--r;
		}

		if (queries[i].lca != -1) {
			change(queries[i].lca);
		}
		ans[queries[i].id] = sum;
		if (queries[i].lca != -1) {
			change(queries[i].lca);
		}
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}

}