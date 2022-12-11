#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int inf = 1e9;

int n;
vector<vector<int> > init;
vector<int> color;

vector<vector<int> > g;
int vsize = 1;

void dfs1(int v, int p, int curr)
{
	for (int to : init[v]) {
		if (to == p) {
			continue;
		}
		if (color[to] != color[v]) {
			g[curr].pb(vsize);
			g[vsize].pb(curr);
			++vsize;
			dfs1(to, v, vsize - 1);
		} else {
			dfs1(to, v, curr);
		}
	}
}

vector<multiset<int> > depth;

void dfs2(int v, int p)
{
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs2(to, v);
		if (depth[to].empty()) {
			depth[v].insert(1);
		} else {
			multiset<int>::iterator it = depth[to].end();
			--it;
			depth[v].insert(*it + 1);
		}
	}
}

int ans = inf;

void dfs3(int v, int p)
{
	if (depth[v].empty()) {
		ans = min(ans, 0);
	} else {
		multiset<int>::iterator it = depth[v].end();
		--it;
		ans = min(ans, *it);
	}
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		int d = 1;
		if (!depth[to].empty()) {
			multiset<int>::iterator it = depth[to].end();
			--it;
			d = *it + 1;
		}
		multiset<int>::iterator it = depth[v].lower_bound(d);
		depth[v].erase(it);
		int new_d = 1;
		if (!depth[v].empty()) {
			it = depth[v].end();
			--it;
			new_d = *it + 1;
		}
		depth[to].insert(new_d);
		dfs3(to, v);
		it = depth[to].lower_bound(new_d);
		depth[to].erase(it);
		depth[v].insert(d);
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	init.resize(n);
	color.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> color[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		init[u].pb(v);
		init[v].pb(u);
	}

	g.resize(n);

	dfs1(0, -1, 0);

	g.resize(vsize);

	depth.resize(vsize);

	dfs2(0, -1);

	dfs3(0, -1);

	cout << ans << "\n";

}