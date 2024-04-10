#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct brod {
	int x, a, p, i;
	ll f;
};

struct baza {
	int x, d,    g;
};

int d[105][105];
int n, m;

struct dependency {
	int u, v;
};

brod a[100005];
baza c[100005];

vector<pair<int, ll>> zlato[105];
int zlato_ptr[105];

dependency dep[1005];
int ugly[100005];
// drugi graf za analizu (scc)
ll p2[2005]; int s2;
basic_string<int> df[2005];
bool reach[2005][2005];

void dfs2(int x, bool* reach) {
	reach[x] = true;
	for (int y : df[x]) {
		if (!reach[y]) {
			dfs2(y, reach);
		}
	}
}
// treci graf
int s3;
int c3[2005];
ll p3[2005];
basic_string<int> e3[2005];

// cetvrti graf
const ll LINF = 1'000'000'000'000'000'000ll;
struct maxflow {
	struct grana {
		int v; ll c, f; int nx;
	};

	vector<grana> g;
	vector<int> start, used, d;

	maxflow(int n) : start(n, -1), used(n, -1), d(n, -1) {}

	void add_edge(int u, int v, ll c) {
		g.push_back({v, c, 0, start[u]});
		start[u] = g.size()-1;
		g.push_back({u, 0, 0, start[v]});
		start[v] = g.size()-1;
	}

	bool bfs(int s, int t) {
		basic_string<int> q = {s};
		size_t qs = 0;
		fill(d.begin(), d.end(), -1);
		d[s] = 0;
		while (qs != q.size()) {
			int x = q[qs++];
			for (int i=start[x]; i!=-1; i=g[i].nx) {
				int y = g[i].v;
				if (d[y] == -1 && g[i].c > g[i].f) {
					d[y] = d[x] + 1;
					q += y;
				}
			}
		}
		return d[t] != -1;
	}

	ll dfs(int x, int t, ll f=LINF) {
		if (x == t)
			return f;
		for (int& i=used[x]; i!=-1; i=g[i].nx) {
			int y = g[i].v;
			if (d[y] == d[x]+1 && g[i].c > g[i].f) {
				ll z = dfs(y, t, min(f, g[i].c - g[i].f));
				if (z > 0) {
					g[i].f += z;
					g[i^1].f -= z;
					return z;
				}
			}
		}
		return 0;
	}

	ll flow(int s, int t) {
		ll z = 0;
		while (bfs(s, t)) {
			used = start;
			while (1) {
				ll f = dfs(s, t);
				if (f > 0) {
					z += f;
				} else {
					break;
				}
			}
		}
		return z;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	memset(d, 63, sizeof(d));
	for (int i=1; i<=n; i++)
		d[i][i] = 0;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		if (u != v) {
			d[u][v] = 1;
			d[v][u] = 1;
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

	int s, b, k;
	cin >> s >> b >> k;
	for (int i=0; i<s; i++) {
		cin >> a[i].x >> a[i].a >> a[i].f >> a[i].p;
		a[i].i = i;
	}
	for (int i=0; i<b; i++) {
		cin >> c[i].x >> c[i].d >> c[i].g;
		zlato[c[i].x].emplace_back(c[i].d, c[i].g);
	}
	for (int i=1; i<=n; i++) {
		sort(zlato[i].begin(), zlato[i].end());
		zlato[i].emplace_back(2e9, -LINF);
		ll z = -LINF;
		for (auto& [x, y] : zlato[i]) {
			ll t = z;
			z = max(z, y);
			y = t;
		}
	}
	sort(a, a+s, [&](brod u, brod v) { return u.a < v.a; });
	for (int i=0; i<s; i++) {
		ll profit = -LINF;
		for (int x=1; x<=n; x++) {
			if (d[a[i].x][x] > a[i].f)
				continue;

			while (zlato[x][zlato_ptr[x]].first <= a[i].a)
				zlato_ptr[x]++;
			profit = max(profit, zlato[x][zlato_ptr[x]].second - a[i].p);
		}
		a[i].f = profit;
	}
	sort(a, a+s, [&](brod u, brod v) { return u.i < v.i; });
	// for (int i=0; i<s; i++)
		// cerr << i << " profit " << a[i].f << '\n';

	for (int i=0; i<k; i++) {
		cin >> dep[i].u >> dep[i].v;
		dep[i].u--;
		dep[i].v--;
		ugly[dep[i].u] = ugly[dep[i].v] = 1;
	}

	ll extra = 0;

	for (int i=0; i<s; i++) {
		if (ugly[i]) {
			ugly[i] = ++s2;
			p2[s2] = a[i].f;
		} else {
			extra += max(0ll, a[i].f);
		}
	}

	for (int i=0; i<k; i++) {
		df[ugly[dep[i].u]] += ugly[dep[i].v];
	}

	for (int i=1; i<=s2; i++) {
		dfs2(i, reach[i]);
	}
	
	for (int i=1; i<=s2; i++) {
		if (c3[i] == 0) {
			s3++;
			for (int j=1; j<=s2; j++) {
				if (reach[i][j] && reach[j][i]) {
					c3[j] = s3;
					p3[s3] += p2[j];
					p3[s3] = clamp(p3[s3], -LINF, LINF);
				}
			}
		}
	}

	for (int i=1; i<=s2; i++)
		for (int j : df[i])
			if (c3[i] != c3[j])
				e3[c3[i]] += c3[j];

	for (int i=1; i<=s3; i++) {
		sort(e3[i].begin(), e3[i].end());
		e3[i].resize(unique(e3[i].begin(), e3[i].end()) - e3[i].begin());
	}

	// flow?
	maxflow mf(s3+2);
	int source = 0;
	int sink = s3+1;
	for (int i=1; i<=s3; i++) {
		// cerr << "objekat " << i << " profita " << p3[i] << '\n';
		if (p3[i] < 0) {
			mf.add_edge(i, sink, -p3[i]);
		} else if (p3[i] > 0) {
			mf.add_edge(source, i, p3[i]);
			extra += p3[i];
		}
	}

	for (int i=1; i<=s3; i++)
		for (int j : e3[i]) {
			// cerr << i << " zavisi od " << j << '\n';
			mf.add_edge(i, j, LINF);
		}

	ll fl = mf.flow(source, sink);
	// cerr << "flow: " << fl << '\n';

	cout << extra - fl << '\n';
}