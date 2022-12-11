#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int tmp;

int diff(const pii& p)
{
	return min(abs(p.first - p.second), tmp - abs(p.first - p.second));
}

struct comp
{
	bool operator()(const pii& a, const pii& b)
	{
		int x = diff(a), y = diff(b);
		if (x != y) {
			return x < y;
		}
		return a < b;
	}
};

vector<vector<int> > faces;

bool comp2(int a, int b)
{
	for (int i = 0; i < 3; ++i) {
		if (faces[a][i] != faces[b][i]) {
			return faces[a][i] < faces[b][i];
		}
	}
	assert(false);
}

struct data
{
	int start;
	vector<int> s;
};

int dd(int x, int y)
{
	int ans = y - x;
	if (ans < 0) {
		ans += tmp;
	}
	return ans;
}

bool clockwise(int a, int b, int c)
{
	return b != a && b != c && dd(a, b) + dd(b, c) == dd(a, c);
}

void solve(vector<vector<int> >& res)
{
	vector<vector<int> > g;
	int n, q;
	cin >> n >> q;
	tmp = n;
	set<pii, comp> aliveEdges;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n) {
			aliveEdges.insert({i, i + 1});
		} else {
			aliveEdges.insert({0, i});
		}
	}
	vector<data> edges(n);
	vector<int> deg(n, 2);
	for (int i = 0; i < n; ++i) {
		edges[i].start = i;
		edges[i].s.pb((i + 1) % n);
		edges[i].s.pb((i - 1 + n) % n);
	}
	set<pii> used;
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u > v) {
			swap(u, v);
		}
		++deg[u];
		++deg[v];
		aliveEdges.insert({u, v});
		edges[u].s.pb(v);
		edges[v].s.pb(u);
	}
	for (int i = 0; i < n; ++i) {
		sort(all(edges[i].s), [&](int a, int b)
	{
		int d1 = a - i;
		if (d1 < 0) {
			d1 += n;
		}
		int d2 = b - i;
		if (d2 < 0) {
			d2 += n;
		}
		return d1 > d2;
	});
	}
	map<pii, int> edgeFace;
	int cnt = 0;
	while (!aliveEdges.empty()) {
		deque<int> cycle;
		int u = aliveEdges.begin()->first;
		int v = aliveEdges.begin()->second;
		aliveEdges.erase(aliveEdges.begin());
		if (u == 0 && v == n - 1) {
			swap(u, v);
		}
		if (used.count({u, v})) {
			continue;
		}
		int curr = v;
		int prev = u;
		cycle.pb(u);
		cycle.pb(v);
		while (curr != u) {
			int lf = -1, rg = sz(edges[curr].s) - 1;
			while (rg - lf > 1) {
				int md = (lf + rg) >> 1;
				int x = edges[curr].s[md];
				if (clockwise(curr, x, prev)) {
					rg = md;
				} else {
					lf = md;
				}
			}
			prev = curr;
			curr = edges[curr].s[rg];
			if (curr != u) {
				cycle.pb(curr);
			}
		}
		/*for (int x : cycle) {
			cout << x << " ";
		}
		cout << "\n";*/
		/*int x = curr;
		int y = -1;
		if (curr != u) {
			curr = u;
			prev = v;
			while (curr != v && deg[curr] == 2) {
				if (*edges[curr].begin() == prev) {
					prev = curr;
					curr = *(++edges[curr].begin());
				} else {
					prev = curr;
					curr = *edges[curr].begin();
				}
				cycle.push_front(curr);
			}
			y = curr;
		}*/
		g.pb(vector<int>());
		faces.pb(vector<int>());
		for (int i = 0; i < sz(cycle); ++i) {
			faces.back().pb(cycle[i]);
			used.insert({cycle[i], cycle[(i + 1) % sz(cycle)]});
			if (cycle[i] + 1 == cycle[(i + 1) % sz(cycle)]) {
				aliveEdges.erase({cycle[i], cycle[(i + 1) % sz(cycle)]});
			}
			if (cycle[i] == 0 && cycle[(i + 1) % sz(cycle)] == n - 1) {
				aliveEdges.erase({cycle[i], cycle[(i + 1) % sz(cycle)]});
			}
			int a = min(cycle[i], cycle[(i + 1) % sz(cycle)]);
			int b = max(cycle[i], cycle[(i + 1) % sz(cycle)]);
			if (edgeFace.count({a, b})) {
				int f = edgeFace[{a, b}];
				g[f].pb(cnt);
				g[cnt].pb(f);
			}
		}
		/*if (y != -1) {
			edgeFace[{min(x, y), max(x, y)}] = cnt;
		}*/
		for (int i = 0; i < sz(cycle); ++i) {
			int x = cycle[i];
			int y = cycle[(i + 1) % sz(cycle)];
			edgeFace[{min(x, y), max(x, y)}] = cnt;
		}
		++cnt;
	}
	/*for (int i = 0; i < cnt; ++i) {
		for (int x : faces[i]) {
			cout << x << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 0; i < cnt; ++i) {
		for (int to : g[i]) {
			cout << i << " " << to << "\n";
		}
	}*/
	vector<int> order;
	for (int i = 0; i < cnt; ++i) {
		order.pb(i);
		sort(all(faces[i]));
		reverse(all(faces[i]));
	}
	sort(all(order), comp2);
	vector<int> pos(cnt);
	for (int i = 0; i < cnt; ++i) {
		pos[order[i]] = i;
	}
	res.resize(cnt);
	for (int i = 0; i < cnt; ++i) {
		for (int v : g[i]) {
			res[pos[i]].pb(pos[v]);
		}
	}
}

vector<vector<int> > g;

vector<int> subtree;
vector<int> color;

void dfs(int v, int p)
{
	subtree[v] = 1;
	for (int to : g[v]) {
		if (color[to] == -1 && p != to) {
			dfs(to, v);
			subtree[v] += subtree[to];
		}
	}
}

int getCentroid(int v, int k, int p)
{
	for (int to : g[v]) {
		if (color[to] == -1 && p != to) {
			if (2 * subtree[to] >= k) {
				return getCentroid(to, k, v);
			}
		}
	}
	return v;
}

void solve(int v, int cc)
{
	dfs(v, -1);
	int k = subtree[v];
	int centroid = getCentroid(v, k, -1);
	color[centroid] = cc;
	for (int to : g[centroid]) {
		if (color[to] == -1) {
			solve(to, cc + 1);
		}
	}
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	//freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(false); // TODO
	cin.tie(0);
	cout.tie(0);

	solve(g);
	int n = sz(g);

	/*for (int i = 0; i < n; ++i) {
		for (int to : g[i]) {
			cout << i << " " << to << "\n";
		}
	}*/

	/*for (int v = 0; v < sz(g); ++v) {
		for (int to : g[v]) {
			cout << v << " " << to << "\n";
		}
	}*/

	subtree.resize(n);
	color.assign(n, -1);

	solve(0, 0);

	for (int i = 0; i < n; ++i) {
		cout << color[i] + 1 << " ";
	}
	cout << "\n";

}