#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int inf = 1e9 + 5;
const int base = 1e9 + 7;
const double eps = 1e-7;
const int maxn = 5e5 + 100;
const ll llinf = 1e18;

int u[maxn], v[maxn];

int p[maxn];
int get(int x) {
	if (x == p[x]) return x;
	return p[x] = get(p[x]);
}

void un(int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return;
	if (rand() % 2) swap(x, y);
	p[x] = y;
}

bool us[maxn];
int up[maxn][25];
int w[maxn][25];

vector<int> g[maxn];

int timer;
int tin[maxn];
int tout[maxn];

void dfs(int v, int p = -1) {
	us[v] = true;
	tin[v] = timer++;

	up[v][0] = p;
	w[v][0] = inf;

	for (int i = 1; i < 25; i++) {
		int kek = up[v][i - 1];
		if (kek == -1) {
			up[v][i] = -1;
			w[v][i] = inf;
			continue;
		}
		up[v][i] = up[kek][i - 1];
		w[v][i] = inf;
	}

	for (int to : g[v]) {
		if (us[to]) continue;
		dfs(to, v);
	}

	tout[v] = timer++;
}

bool U(int a, int b) {
	if (tin[a] <= tin[b] && tout[a] >= tout[b])
		return true;
	return false;
}

int lca(int a, int b) {
	if (U(a, b)) return a;
	if (U(b, a)) return b;

	for (int i = 24; i >= 0; i--) {
		if (up[a][i] == -1) continue;
		if (!U(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

void upd(int fr, int to, int c) {
	int l = lca(fr, to);
	if (l != fr) {
		for (int i = 24; i >= 0; i--) {
			int v = up[fr][i];
			if (v == -1) continue;
			if (U(l, v)) {
				w[fr][i] = min(w[fr][i], c);
				fr = v;
			}
		}
		assert(fr == l);
	}
	if (l != to) {
		for (int i = 24; i >= 0; i--) {
			int v = up[to][i];
			if (v == -1) continue;
			if (U(l, v)) {
				w[to][i] = min(w[to][i], c);
				to = v;
			}
		}
		assert(to == l);
	}
}

int main() {
	srand(time(NULL));
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// ios_base::sync_with_stdio(false);

	int n, k, m;
	// cin >> n >> k >> m;
	scanf ("%d%d%d", &n, &k, &m);

	for (int i = 0; i < n; i++)
		p[i] = i;

	memset(up, -1, sizeof(up));

	for (int i = 0; i < k; i++) {
		// cin >> u[i] >> v[i];
		scanf ("%d%d", &u[i], &v[i]);
		u[i]--, v[i]--;
		un(u[i], v[i]);
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}

	// for (int i = 0; i < n; i++)
	// 	if (!us[i])
	// 		dfs(i);

	vector<pair<int, pair<int, int> > > e, eu;
	for (int i = 0; i < m; i++) {
		int x, y, c;
		// cin >> x >> y >> c;
		scanf ("%d%d%d", &x, &y, &c);
		x--, y--;
		e.push_back(mp(c, mp(x, y)));
		// if (get(x) != get(y)) continue;
	}

	sort(e.begin(), e.end());

	map<pair<int, int>, bool> bad;

	for (int i = 0; i < m; i++) {
		int u = e[i].s.f, v = e[i].s.s;
		if (get(u) != get(v)) {
			un(u, v);
			g[u].pb(v);
			g[v].pb(u);
			bad[minmax(u, v)] = true;
		} else {
			eu.pb(e[i]);
		}	
	}

	dfs(0);

	for (auto e : eu) {
		upd(e.s.f, e.s.s, e.f);
	}

	for (int j = 24; j > 0; j--) 
		for (int i = 0; i < n; i++) {
			if (up[i][j] != -1) {
				int v = up[i][j - 1];
				w[i][j - 1] = min(w[i][j - 1], w[i][j]);
				w[v][j - 1] = min(w[v][j - 1], w[i][j]);
			}
		}

	ll res = 0;
	for (int i = 0; i < n; i++) {
		int x = up[i][0];
		if (bad.count(minmax(i, x))) continue;

		if (up[i][0] != -1 && w[i][0] == inf) {
			cout << -1 << endl;
			return 0;
		}
		if (up[i][0] != -1)
			res += w[i][0];
	}
	cout << res << endl;
	return 0;
}